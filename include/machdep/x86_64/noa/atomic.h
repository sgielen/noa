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
 * s = *a;
 * *a += b;
 * return (s);
 */

static inline long
atomic_fetchadd_long(volatile long *a, long b)
{

	asm volatile ("lock xaddq %0, %1" : "+r" (b), "=m" (*a) : "m" (*a));
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

	asm volatile ("lock xchg %0, %1" : "+r" (b), "=m" (*a) : "m" (*a));
	return (b);
}

#define	atomic_fetchadd_intmax_t(a, b)		atomic_fetchadd_long(a, b)
#define	atomic_fetchstore_intmax_t(a, b)	atomic_fetchstore_long(a, b)

#endif /* !_NOA_ATOMIC_H_ */
