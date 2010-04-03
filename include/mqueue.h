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

#ifndef _MQUEUE_H_
#define	_MQUEUE_H_

#define	__NEED_PTHREAD_ATTR_T
#define	__NEED_SIZE_T
#define	__NEED_SSIZE_T
#define	__NEED_STRUCT_TIMESPEC

#include <noa/types.h>

typedef int mqd_t;

struct sigevent;

__ABI_STRUCT(mq_attr, 32, {
	long	mq_flags;
	long	mq_maxmsg;
	long	mq_msgsize;
	long	mq_curmsgs;
})

__BEGIN_DECLS
int	 mq_close(mqd_t);
int	 mq_getattr(mqd_t, struct mq_attr *);
int	 mq_notify(mqd_t, const struct sigevent *);
mqd_t	 mq_open(const char *, int, ...);
ssize_t	 mq_receive(mqd_t, char *, size_t, unsigned *);
int	 mq_send(mqd_t, const char *, size_t, unsigned);
int	 mq_setattr(mqd_t, const struct mq_attr *restrict,
	     struct mq_attr *restrict);
ssize_t	 mq_timedreceive(mqd_t, char *restrict, size_t,
	     unsigned *restrict, const struct timespec *restrict);
int	 mq_timedsend(mqd_t, const char *, size_t, unsigned,
	     const struct timespec *);
int	 mq_unlink(const char *);
__END_DECLS

#endif /* !_MQUEUE_H_ */
