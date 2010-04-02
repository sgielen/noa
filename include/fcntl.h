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

#ifndef _FCNTL_H_
#define	_FCNTL_H_

#define	__NEED_MODE_T
#define	__NEED_OFF_T
#define	__NEED_PID_T

#include <noa/types.h>

#define	F_DUPFD			1
#define	F_DUPFD_CLOEXEC		2
#define	F_GETFD			3
#define	F_SETFD			4
#define	F_GETFL			5
#define	F_SETFL			6
#define	F_GETLK			7
#define	F_SETLK			8
#define	F_SETLKW		9
#define	F_GETOWN		10
#define	F_SETOWN		11

#define	FD_CLOEXEC		0x1

#define	F_RDLCK			1
#define	F_UNLCK			2
#define	F_WRLCK			3

#define	O_CREAT			0x00001
#define	O_EXCL			0x00002
#define	O_NOCTTY		0x00004
#define	O_TRUNC			0x00008
#define	O_TTY_INIT		0x00010
#define	O_APPEND		0x00020
#define	O_DSYNC			0x00040
#define	O_NONBLOCK		0x00080
#define	O_RSYNC			0x00100
#define	O_SYNC			0x00200
#define	O_ACCMODE		(O_EXEC|O_RDWR|O_SEARCH)
#define	O_EXEC			0x00400
#define	O_RDONLY		0x00800
#define	O_RDWR			(O_RDONLY|O_WRONLY)
#define	O_SEARCH		0x01000
#define	O_WRONLY		0x02000
#define	O_CLOEXEC		0x04000
#define	O_DIRECTORY		0x08000
#define	O_NOFOLLOW		0x10000

#define	AT_FDCWD		(-1)

#define	AT_EACCESS		0x1
#define	AT_SYMLINK_NOFOLLOW	0x2
#define	AT_SYMLINK_FOLLOW	0x4
#define	AT_REMOVEDIR		0x8

#define	POSIX_FADV_DONTNEED	1
#define	POSIX_FADV_NOREUSE	2
#define	POSIX_FADV_NORMAL	3
#define	POSIX_FADV_RANDOM	4
#define	POSIX_FADV_SEQUENTIAL	5
#define	POSIX_FADV_WILLNEED	6

__ABI_STRUCT(flock, 32, {
	short	l_type;
	short	l_whence;
	off_t	l_start;
	off_t	l_len;
	pid_t	l_pid;
})

__BEGIN_DECLS
int	 creat(const char *, mode_t);
int	 fcntl(int, int, ...);
int	 open(const char *, int, ...);
int	 openat(int, const char *, int, ...);
int	 posix_fadvise(int, off_t, off_t, int);
int	 posix_fallocate(int, off_t, off_t);
__END_DECLS

#endif /* !_FCNTL_H_ */
