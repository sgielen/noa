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

#ifndef _SYS_SELECT_H_
#define	_SYS_SELECT_H_

#define	__NEED_SIGSET_T
#define	__NEED_STRUCT_TIMESPEC
#define	__NEED_STRUCT_TIMEVAL

#include <noa/types.h>

#define	FD_SETSIZE	1024
#define	__FD_BPW	(sizeof(long) * 8)
#define	__FD_WORD(b)	((b) / __FD_BPW)
#define	__FD_BIT(b)	((b) % __FD_BPW)

#define	FD_CLR(fd, fdset) \
	((fdset)->__fd_bits[__FD_WORD(fd)] &= ~__FD_BIT(fd))
#define	FD_ISSET(fd, fdset) \
	((fdset)->__fd_bits[__FD_WORD(fd)] & __FD_BIT(fd) != 0)
#define	FD_SET(fd, fdset) \
	((fdset)->__fd_bits[__FD_WORD(fd)] |= __FD_BIT(fd))
#define	FD_ZERO(fdset) do { \
	unsigned int __i;					\
	for (__i = 0; __i < __FD_WORD(FD_SETSIZE); __i++)	\
		fdset->__fd_bits[__i] = 0;			\
} while (0)

typedef struct {
	long	__fd_bits[(FD_SETSIZE + __FD_BPW - 1) / __FD_BPW];
} fd_set;

__BEGIN_DECLS
int	 pselect(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	     const struct timespec *restrict, const sigset_t *restrict);
int	 select(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
	     struct timeval *restrict);
__END_DECLS

#endif /* !_SYS_SELECT_H_ */
