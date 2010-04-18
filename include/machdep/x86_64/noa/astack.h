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

#ifndef _NOA_ASTACK_H_
#define	_NOA_ASTACK_H_

#define	__NEED_SIZE_T

#include <noa/atomic.h>
#include <noa/types.h>

typedef struct {
	void		*ash_first;
	unsigned long	 ash_cnt;
} astack_head_t;

typedef struct {
	void		*ash_next;
} astack_entry_t;

static inline void
__astack_init(astack_head_t *head)
{

	head->ash_first = NULL;
	head->ash_cnt = 0;
}

static inline void *
__astack_pop(astack_head_t *head __unused, size_t offset __unused)
{
#if 0
	astack_head_t ohead, nhead;
	void *ret;

	do {
		atomic(ohead = nhead = *head);
		ret = nhead.ash_first
		if (ret == NULL)
			return (NULL);
		nhead.ash_first = ret.ash_next;
		nhead.ash_cnt++;
	} while (!atomic(head, ohead, nhead));

	return (ret);
#endif
	return (NULL);
}

static inline void
__astack_push(astack_head_t *head __unused, void *elm __unused, size_t offset __unused)
{
#if 0
	astack_head_t ohead, nhead;

	do {
		atomic(ohead = nhead = *head);
		elm->next = ohead.first;
		nhead.ash_first = elm;
		nhead.ash_cnt++;
	} while (!atomic(head, ohead, nhead));
#endif
}

#define	ASTACK_INIT(head) \
	__astack_init(head)
#define	ASTACK_POP(head, type, field) \
	(struct type *)__astack_pop(head,				\
	    (char *)&(((struct type *)0)->field) - (char *)0)
#define	ASTACK_PUSH(head, elm, field) \
	__astack_push(head, (elm), (char *)&((elm)->field) - (char *)(elm))

#endif /* !_NOA_ASTACK_H_ */
