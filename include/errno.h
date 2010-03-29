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

#ifndef _ERRNO_H_
#define	_ERRNO_H_

#include <noa/cdefs.h>

#define	E2BIG		1
#define	EACCES		2
#define	EADDRINUSE	3
#define	EADDRNOTAVAIL	4
#define	EAFNOSUPPORT	5
#define	EAGAIN		6
#define	EALREADY	7
#define	EBADF		8
#define	EBADMSG		9
#define	EBUSY		10
#define	ECANCELED	11
#define	ECHILD		12
#define	ECONNABORTED	13
#define	ECONNREFUSED	14
#define	ECONNRESET	15
#define	EDEADLK		16
#define	EDESTADDRREQ	17
#define	EDOM		18
#define	EDQUOT		19
#define	EEXIST		20
#define	EFAULT		21
#define	EFBIG		22
#define	EHOSTUNREACH	23
#define	EIDRM		24
#define	EILSEQ		25
#define	EINPROGRESS	26
#define	EINTR		27
#define	EINVAL		28
#define	EIO		29
#define	EISCONN		30
#define	EISDIR		31
#define	ELOOP		32
#define	EMFILE		33
#define	EMLINK		34
#define	EMSGSIZE	35
#define	EMULTIHOP	36
#define	ENAMETOOLONG	37
#define	ENETDOWN	38
#define	ENETRESET	39
#define	ENETUNREACH	40
#define	ENFILE		41
#define	ENOBUFS		42
#define	ENODEV		43
#define	ENOENT		44
#define	ENOEXEC		45
#define	ENOLCK		46
#define	ENOLINK		47
#define	ENOMEM		48
#define	ENOMSG		49
#define	ENOPROTOOPT	50
#define	ENOSPC		51
#define	ENOSYS		52
#define	ENOTCONN	53
#define	ENOTDIR		54
#define	ENOTEMPTY	55
#define	ENOTRECOVERABLE	56
#define	ENOTSOCK	57
#define	ENOTSUP		58
#define	ENOTTY		59
#define	ENXIO		60
#define	EOPNOTSUPP	61
#define	EOVERFLOW	62
#define	EOWNERDEAD	63
#define	EPERM		64
#define	EPIPE		65
#define	EPROTO		66
#define	EPROTONOSUPPORT	67
#define	EPROTOTYPE	68
#define	ERANGE		69
#define	EROFS		70
#define	ESPIPE		71
#define	ESRCH		72
#define	ESTALE		73
#define	ETIMEDOUT	74
#define	ETXTBSY		75
#define	EWOULDBLOCK	76
#define	EXDEV		77

__BEGIN_DECLS
extern __thread int errno;
__END_DECLS

#endif /* !_ERRNO_H_ */
