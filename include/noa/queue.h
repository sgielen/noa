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

#ifndef _NOA_QUEUE_H_
#define	_NOA_QUEUE_H_

#include <noa/atomic.h>

#define	DUMPQ_HEAD(name, type) \
struct name {								\
	volatile struct type *dqh_first;				\
}

#define	DUMPQ_ENTRY(type) \
struct {								\
	volatile struct type *dqe_next;					\
}

#define	DUMPQ_INIT(head) do { \
	(head)->dqh_first = NULL;					\
} while (0)

#define	DUMPQ_INSERT_HEAD(head, elm, field) do { \
	(elm)->field.dqe_next = (head)->dqh_first;			\
} while (!atomic_cmpset_ptr(&(head)->dqh_first, (elm)->field.dqe_next, (elm)))

#define	DUMPQ_REMOVE_HEAD(elm, head, field) do { \
	elm = (void *)(head)->dqh_first;				\
} while (elm != NULL && !atomic_cmpset_ptr(&(head)->dqh_first,		\
    (elm)->field.dqe_next, (elm)))

#endif /* !_NOA_QUEUE_H_ */
