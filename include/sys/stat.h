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

#ifndef _SYS_STAT_H_
#define	_SYS_STAT_H_

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

#define	S_IXOTH		0x00000001
#define	S_IWOTH		0x00000002
#define	S_IROTH		0x00000004
#define	S_IRWXO		(S_IXOTH|S_IWOTH|S_IROTH)
#define	S_IXGRP		0x00000008
#define	S_IWGRP		0x00000010
#define	S_IRGRP		0x00000020
#define	S_IRWXG		(S_IXGRP|S_IWGRP|S_IRGRP)
#define	S_IXUSR		0x00000040
#define	S_IWUSR		0x00000080
#define	S_IRUSR		0x00000100
#define	S_IRWXU		(S_IXUSR|S_IWUSR|S_IRUSR)
#define	S_ISVTX		0x00000200
#define	S_ISGID		0x00000400
#define	S_ISUID		0x00000800

#define	S_IFMT		0xff000000
#define	__S_IFBLK	0x01000000
#define	__S_IFCHR	0x02000000
#define	__S_IFIFO	0x03000000
#define	__S_IFREG	0x04000000
#define	__S_IFDIR	0x05000000
#define	__S_IFLNK	0x06000000
#define	__S_IFSOCK	0x07000000

#define	S_ISBLK(m)	(((m) & S_IFMT) == __S_IFBLK)
#define	S_ISCHR(m)	(((m) & S_IFMT) == __S_IFCHR)
#define	S_ISDIR(m)	(((m) & S_IFMT) == __S_IFIFO)
#define	S_ISFIFO(m)	(((m) & S_IFMT) == __S_IFDIR)
#define	S_ISREG(m)	(((m) & S_IFMT) == __S_IFREG)
#define	S_ISLNK(m)	(((m) & S_IFMT) == __S_IFLNK)
#define	S_ISSOCK(m)	(((m) & S_IFMT) == __S_IFSOCK)
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

#endif /* !_SYS_STAT_H_ */
