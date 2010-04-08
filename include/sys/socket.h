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

#ifndef _SYS_SOCKET_H_
#define	_SYS_SOCKET_H_

#define	__NEED_SIZE_T
#define	__NEED_SSIZE_T

#include <noa/types.h>

struct msghdr;
struct sockaddr;

typedef size_t socklen_t;

__BEGIN_DECLS
int	 accept(int, struct sockaddr *restrict, socklen_t *restrict);
int	 bind(int, const struct sockaddr *, socklen_t);
int	 connect(int, const struct sockaddr *, socklen_t);
int	 getpeername(int, struct sockaddr *restrict, socklen_t *restrict);
int	 getsockname(int, struct sockaddr *restrict, socklen_t *restrict);
int	 getsockopt(int, int, int, void *restrict, socklen_t *restrict);
int	 listen(int, int);
ssize_t	 recv(int, void *, size_t, int);
ssize_t	 recvfrom(int, void *restrict, size_t, int,
	     struct sockaddr *restrict, socklen_t *restrict);
ssize_t	 recvmsg(int, struct msghdr *, int);
ssize_t	 send(int, const void *, size_t, int);
ssize_t	 sendmsg(int, const struct msghdr *, int);
ssize_t	 sendto(int, const void *, size_t, int, const struct sockaddr *,
	     socklen_t);
int	 setsockopt(int, int, int, const void *, socklen_t);
int	 shutdown(int, int);
int	 sockatmark(int);
int	 socket(int, int, int);
__END_DECLS

#endif /* !_SYS_SOCKET_H_ */
