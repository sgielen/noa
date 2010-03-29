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

#ifndef _SYS_UTSNAME_H_
#define	_SYS_UTSNAME_H_

#define	__NEED_DEV_T
#define	__NEED_GID_T
#define	__NEED_INO_T
#define	__NEED_MODE_T
#define	__NEED_NLINK_T
#define	__NEED_OFF_T
#define	__NEED_STRUCT_TIMESPEC
#define	__NEED_UID_T

#include <noa/cdefs.h>
#include <noa/types.h>

struct stat {
	dev_t	st_dev;
	ino_t	st_ino;
	mode_t	st_mode;
	nlink_t	st_nlink;
	uid_t	st_uid;
	gid_t	st_gid;
	off_t	st_size;
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
};

#define	st_atime	st_atim.tv_sec
#define	st_mtime	st_mtim.tv_sec
#define	st_ctime	st_ctim.tv_sec

#define	S_IXOTH		00001
#define	S_IWOTH		00002
#define	S_IROTH		00004
#define	S_IRWXO		00007
#define	S_IXGRP		00010
#define	S_IWGRP		00020
#define	S_IRGRP		00040
#define	S_IRWXG		00070
#define	S_IXUSR		00100
#define	S_IWUSR		00200
#define	S_IRUSR		00400
#define	S_IRWXU		00700
#define	S_ISVTX		01000
#define	S_ISGID		02000
#define	S_ISUID		04000

#define	S_ISBLK(m)	0
#define	S_ISCHR(m)	TODO
#define	S_ISDIR(m)	TODO
#define	S_ISFIFO(m)	TODO
#define	S_ISREG(m)	TODO
#define	S_ISLNK(m)	TODO
#define	S_ISSOCK(m)	TODO
#define	S_TYPEISMQ(m)	TODO
#define	S_TYPEISSEM(m)	TODO
#define	S_TYPEISSHM(m)	TODO

#define	UTIME_NOW	(-1)
#define	UTIME_OMIT	(-2)

__BEGIN_DECLS
int	 chmod(const char *, mode_t);
int	 fchmod(int, mode_t);
int	 fchmodat(int, const char *, mode_t, int);
int	 fstat(int, struct stat *);
int	 fstatat(int, const char *restrict, struct stat *restrict, int);
int	 futimens(int, const struct timespec[2]);
int	 lstat(const char *restrict, struct stat *restrict);
int	 mkdir(const char *, mode_t);
int	 mkdirat(int, const char *, mode_t);
int	 mkfifo(const char *, mode_t);
int	 mkfifoat(int, const char *, mode_t);
int	 stat(const char *restrict, struct stat *restrict);
mode_t	 umask(mode_t);
int	 utimensat(int, const char *, const struct timespec[2], int);
__END_DECLS

#endif /* !_SYS_UTSNAME_H_ */
