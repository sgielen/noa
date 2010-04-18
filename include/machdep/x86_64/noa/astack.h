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

#include <noa/atomic.h>

/*
 * An atomic stack implementation for x86-64.
 *
 * We take care of the ABA problem by using the fact that on current
 * x86-64 hardware, the top 16 bits of the pointer are not yet used. We
 * store the address in a signed long, of which we use the bottom 16
 * bits to store a counter.
 */

#define	ASTACK_HEAD(name, type)						\
struct name {								\
	signed long	 ash_first;					\
}

#define	ASTACK_ENTRY(type)						\
struct {								\
	struct type	*ase_next;					\
}

#define	_ASTACK_NEXT(elm, field)	((elm)->field.ase_next)

#define	_ASTACK_IDX(p, oh) \
	(((signed long)(p) << 16) | ((oh) & 0xffff))
#define	_ASTACK_PTR(idx) \
	((void *)(idx >> 16))

#define	ASTACK_INIT(head) do {						\
	(head)->ash_first = 0;						\
} while (0)

#define	ASTACK_INSERT_HEAD(head, elm, field) do {			\
	signed long _oh, _nh;						\
	do {								\
		_oh = (head)->ash_first;				\
		_ASTACK_NEXT(elm, field) = _ASTACK_PTR(_oh);		\
		_nh = _ASTACK_IDX(elm, _oh);				\
	} while (!atomic_cmpset_long(&(head)->ash_first, _oh, _nh));	\
} while (0)

#define	ASTACK_REMOVE_HEAD(head, elm, field) do {			\
	signed long _oh, _nh;						\
	do {								\
		_oh = (head)->ash_first;				\
		if (((elm) = _ASTACK_PTR(_oh)) == NULL)			\
			break;						\
		_nh = _ASTACK_IDX(_ASTACK_NEXT(elm, field), _oh + 1);	\
	} while (!atomic_cmpset_long(&(head)->ash_first, _oh, _nh));	\
} while (0)

#endif /* !_NOA_ASTACK_H_ */
