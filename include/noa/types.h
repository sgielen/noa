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

#ifndef _NOA_TYPES_H_
#define	_NOA_TYPES_H_

#include <noa/machine/types.h>

/*
 * Primitive types.
 */

#if defined(__NEED_CLOCK_T) && !defined(__HAVE_CLOCK_T)
typedef __int64_t clock_t;
#define	__HAVE_CLOCK_T
#endif

#if defined(__NEED_CLOCKID_T) && !defined(__HAVE_CLOCKID_T)
typedef int clockid_t;
#define	__HAVE_CLOCKID_T
#endif

#if defined(__NEED_LOCALE_T) && !defined(__HAVE_LOCALE_T)
typedef struct __locale_t *locale_t;
#define	__HAVE_LOCALE_T
#endif

#if defined(__NEED_OFF_T) && !defined(__HAVE_OFF_T)
typedef __int64_t off_t;
#define	__HAVE_OFF_T
#endif

#if defined(__NEED_SIZE_T) && !defined(__HAVE_SIZE_T)
typedef __size_t size_t;
#define	__HAVE_SIZE_T
#endif

#if defined(__NEED_TIME_T) && !defined(__HAVE_TIME_T)
typedef __int64_t time_t;
#define	__HAVE_TIME_T
#endif

#if defined(__NEED_TIMER_T) && !defined(__HAVE_TIMER_T)
typedef int timer_t;
#define	__HAVE_TIMER_T
#endif

/*
 * Structures.
 */

#if defined(__NEED_STRUCT_TIMESPEC) && !defined(__HAVE_STRUCT_TIMESPEC)
struct timespec {
	time_t	tv_sec;
	long	tv_nsec;
};
#define	__HAVE_STRUCT_TIMESPEC
#endif

#endif /* !_NOA_TYPES_H_ */
