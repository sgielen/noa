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

#ifndef _NOA_FDCALL_H_
#define	_NOA_FDCALL_H_

#define	__NEED_GID_T
#define	__NEED_OFF_T
#define	__NEED_SIZE_T
#define	__NEED_UID_T

#include <noa/types.h>

#define	_FDC(isiz, osiz, group, num) \
	(((uint64_t)isiz) << 40 | ((uint64_t)osiz) << 16 | \
	((uint64_t)group) << 8 | ((uint64_t)num))
#define	_FD(group, num) \
	_FDC(0, 0, (group), (num))
#define	_FDI(group, num, itype) \
	_FDC(sizeof(itype), 0, (group), (num))
#define	_FDO(group, num, otype) \
	_FDC(0, sizeof(otype), (group), (num))
#define	_FDIO(group, num, itype, otype) \
	_FDC(sizeof(itype), sizeof(otype), (group), (num))

struct fd_advise {
	off_t	offset;
	off_t	len;
	int	advice;
};

struct fd_allocate {
	off_t	offset;
	off_t	len;
};

struct fd_chown {
	uid_t	owner;
	gid_t	group;
};

struct fd_rw {
	const struct iovec *iov;
	size_t	iovcnt;
	off_t	offset;
	int	whence;
};

struct fd_seek {
	off_t	offset;
	int	whence;
};

/* File descriptors. */
#define	FD_ADVISE	 _FDI('f', 1, struct fd_advise)
#define	FD_ALLOCATE	 _FDI('f', 2, struct fd_allocate)
#define	FD_CHMOD	 _FDI('f', 3, mode_t)
#define	FD_CHOWN	 _FDI('f', 4, struct fd_chown)
#define	FD_READ		_FDIO('f', 5, struct fd_rw, size_t)
#define	FD_STAT		 _FDO('f', 6, struct stat)
#define	FD_SYNC		  _FD('f', 7)
#define	FD_SEEK		_FDIO('f', 8, struct fd_seek, off_t)
#define	FD_TRUNCATE	 _FDI('f', 9, off_t)
#define	FD_WRITE	_FDIO('f', 10, struct fd_rw, size_t)

/* TTYs. */
#define	TTY_DRAIN	  _FD('t', 1)
#define	TTY_FLUSH	 _FDI('t', 2, int)
#define	TTY_GETA	 _FDO('t', 3, struct termios)
#define	TTY_GETPGRP	 _FDO('t', 4, pid_t)
#define	TTY_GETSID	 _FDO('t', 5, pid_t)
#define	TTY_ISAPTM	  _FD('t', 6)
#define	TTY_ISATTY	  _FD('t', 7)
#define	TTY_SETAD	 _FDI('t', 8, struct termios)
#define	TTY_SETAF	 _FDI('t', 9, struct termios)
#define	TTY_SETAN	 _FDI('t', 10, struct termios)
#define	TTY_SETPGRP	 _FDI('t', 11, pid_t)

#endif /* !_NOA_FDCALL_H_ */
