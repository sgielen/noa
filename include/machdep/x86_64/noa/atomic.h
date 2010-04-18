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

#ifndef _NOA_ATOMIC_H_
#define	_NOA_ATOMIC_H_

/*
 * There is no need to use "lock" when we don't do SMP, since a single
 * CPU is always consistent with its own cache.
 */
#if defined(_KERNEL) && defined(NO_SMP)
#define	_LOCK	""
#else
#define	_LOCK	"lock;"
#endif

/*
 * *a += b;
 */
static inline void
atomic_add_long(volatile long *a, long b)
{

	asm volatile (_LOCK "addq %1, %0" : "=m" (*a) : "ir" (b), "m" (*a));
}

/*
 * if (*a == b) {
 * 	*a = c;
 * 	return (1);
 * } else {
 * 	return (0);
 * }
 */

static inline long
atomic_cmpset_long(volatile long *a, long b, long c)
{
	char ret;

	asm volatile(_LOCK "cmpxchgq %2, %1; sete %0; 1:"
	    : "=a" (ret), "=m" (*a) : "r" (c), "a" (b), "m" (*a) : "memory");
	return (ret);
}

/*
 * s = *a;
 * *a += b;
 * return (s);
 */

static inline long
atomic_fetchadd_long(volatile long *a, long b)
{

	asm volatile (_LOCK "xaddq %0, %1" : "+r" (b), "=m" (*a) : "m" (*a));
	return (b);
}

/*
 * s = *a;
 * *a = b;
 * return (s);
 */

static inline long
atomic_fetchstore_long(volatile long *a, long b)
{

	asm volatile (_LOCK "xchg %0, %1" : "+r" (b), "=m" (*a) : "m" (*a));
	return (b);
}

#define	atomic_cmpset_ptr(a, b, c) \
	(void *)atomic_cmpset_long((volatile long *)a, (long)b, (long)c)


#define	atomic_fetchadd_intmax_t(a, b)		atomic_fetchadd_long(a, b)
#define	atomic_fetchstore_intmax_t(a, b)	atomic_fetchstore_long(a, b)

#endif /* !_NOA_ATOMIC_H_ */
