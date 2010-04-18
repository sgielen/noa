/*-
 * Copyright (c) 2010 The Noa Project, http://noaproject.org/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <noa/vmparam.h>
#include <assert.h>
#include <kernel.h>

struct slabentry {
	ASTACK_ENTRY(slabentry) se_next;
	char		 se_data[];
};

struct slabpage {
	ASTACK_ENTRY(slabpage) sp_next;
	size_t		 sp_left;
	char		 sp_data[];
};

static struct mutex slablock;
static struct cond slabavail;

static ASTACK_HEAD(, slabpage) slabpagelist[PAGE_SHIFT + 1];

void
slab_give(void *page)
{
	struct slabpage *sp = page;

	mutex_xlock(&slablock);
	sp->sp_left = PAGE_SIZE;
	ASTACK_INSERT_HEAD(&slabpagelist[PAGE_SHIFT], sp, sp_next);
	cond_signal(&slabavail, 0);
	mutex_xlock(&slablock);
}

void *
slab_alloc_nowait(struct slab *sl)
{
	struct slabentry *se;
	struct slabpage *sp;
	size_t left;
	unsigned int log;

	/* Allocate from the slab's free list. */
	ASTACK_REMOVE_HEAD(&sl->sl_freelist, se, se_next);
	if (se != NULL)
		return (se->se_data);

	for (log = log2ceil(sl->sl_size); log <= PAGE_SHIFT; log++) {
		/* Get partially filled or empty page. */
		ASTACK_REMOVE_HEAD(&slabpagelist[log], sp, sp_next);
		if (sp == NULL)
			continue;

		/* Allocate new instance in this page. */
		assert(sp->sp_left >= sl->sl_size);
		left = sp->sp_left - sl->sl_size;
		se = (struct slabentry *)((char *)sp + sp->sp_left);
		sl->sl_ctor(se->se_data);

		/* Store the page back in the free space table. */
		if (left >= sizeof(struct slabpage)) {
			sp->sp_left = left;
			log = log2floor(sp->sp_left);
			ASTACK_INSERT_HEAD(&slabpagelist[log], sp, sp_next);
		}

		return (se->se_data);
	}
	return (NULL);
}

void *
slab_alloc_waitok(struct slab *sl)
{
	void *ret;

	/* Fast path. */
	ret = slab_alloc_nowait(sl);
	if (ret != NULL)
		return (ret);

	/* Allocation failed. Try with blocking. */
	mutex_slock(&slablock);
	while ((ret = slab_alloc_nowait(sl)) == NULL)
		cond_wait(&slabavail, &slablock, NULL, 0);
	mutex_sunlock(&slablock);
	return (ret);
}

void
slab_free(struct slab *sl, void *addr)
{
	struct slabentry *se;

	se = __containerof(addr, slabentry, se_data);
	ASTACK_INSERT_HEAD(&sl->sl_freelist, se, se_next);
}

void
_slab_init(struct slab *sl, size_t size, void (*ctor)(void *))
{

	ASTACK_INIT(&sl->sl_freelist);
	/* Reserve additional space for the free list pointer. */
	/* XXX: ROUND UP TO MAXIMUM ALIGNMENT! */
	sl->sl_size = size + sizeof(struct slabentry);
	assert(sl->sl_size > sizeof(struct slabentry) &&
	    sl->sl_size <= PAGE_SIZE);
	sl->sl_ctor = ctor;
}
