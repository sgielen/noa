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

#include <kernel.h>

/*
 * Thread and process group red-black tree.
 */

static inline int
processgroup_idcmp(struct processgroup *pg, cookie_t pgid)
{

	if (pg->pg_id > pgid)
		return (-1);
	else if (pg->pg_id < pgid)
		return (1);
	return (0);
}

static inline int
thread_idcmp(struct thread *td, cookie_t tid)
{

	if (td->td_id > tid)
		return (-1);
	else if (td->td_id < tid)
		return (1);
	return (0);
}

RBTREE_HEAD(processgroup_rbhead, processgroup);
RBTREE_FUNCS(processgroup_rbtree, processgroup_rbhead, processgroup,
    pg_tree, processgroup_idcmp, cookie_t);
RBTREE_HEAD(thread_rbhead, thread);
RBTREE_FUNCS(thread_rbtree, thread_rbhead, thread, td_tree,
    thread_idcmp, cookie_t);

struct mutex processtopo;
static struct processgroup_rbhead processgrouptree;
static struct thread_rbhead threadtree;

struct process *
process_lookup(cookie_t pid)
{
	struct thread *td;
	struct process *p;

	td = thread_lookup(pid);
	if (td == NULL)
		return (NULL);
	p = td->td_process;
	if (p->p_id != pid)
		return (NULL);
	return (p);
}

struct processgroup *
processgroup_lookup(cookie_t pgid)
{
	struct processgroup *pg;

	mutex_assert(&processtopo);
	pg = processgroup_rbtree_lookup(&processgrouptree, pgid);
	return (pg);
}

struct thread *
thread_lookup(cookie_t tid)
{
	struct thread *td;

	mutex_assert(&processtopo);
	td = thread_rbtree_lookup(&threadtree, tid);
	return (td);
}
