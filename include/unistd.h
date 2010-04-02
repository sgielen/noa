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

#ifndef _UNISTD_H_
#define	_UNISTD_H_

#define	__NEED_GID_T
#define	__NEED_INTPTR_T
#define	__NEED_OFF_T
#define	__NEED_PID_T
#define	__NEED_SIZE_T
#define	__NEED_SSIZE_T
#define	__NEED_UID_T

#include <noa/cdefs.h>
#include <noa/types.h>

#define	STDIN_FILENO		0
#define	STDOUT_FILENO		1
#define	STDERR_FILENO		2

#define	_POSIX_VDISABLE		0xff

__BEGIN_DECLS
int	 access(const char *, int);
unsigned	 alarm(unsigned);
int	 chdir(const char *);
int	 chown(const char *, uid_t, gid_t);
int	 close(int);
size_t	 confstr(int, char *, size_t);
char	*ctermid(char *);
int	 dup(int);
int	 dup2(int, int);
void	 _exit(int);
int	 execl(const char *, const char *, ...);
int	 execle(const char *, const char *, ...);
int	 execlp(const char *, const char *, ...);
int	 execv(const char *, char *const []);
int	 execve(const char *, char *const [], char *const []);
int	 execvp(const char *, char *const []);
int	 faccessat(int, const char *, int, int);
int	 fchdir(int);
int	 fchown(int, uid_t, gid_t);
int	 fchownat(int, const char *, uid_t, gid_t, int);
int	 fdatasync(int);
int	 fexecve(int, char *const [], char *const []);
pid_t	 fork(void);
long	 fpathconf(int, int);
int	 fsync(int);
int	 ftruncate(int, off_t);
char	*getcwd(char *, size_t);
gid_t	 getegid(void);
uid_t	 geteuid(void);
gid_t	 getgid(void);
int	 getgroups(int, gid_t []);
int	 gethostname(char *, size_t);
char	*getlogin(void);
int	 getlogin_r(char *, size_t);
int	 getopt(int, char * const [], const char *);
pid_t	 getpgid(pid_t);
pid_t	 getpgrp(void);
pid_t	 getpid(void);
pid_t	 getppid(void);
pid_t	 getsid(pid_t);
uid_t	 getuid(void);
int	 isatty(int);
int	 lchown(const char *, uid_t, gid_t);
int	 link(const char *, const char *);
int	 linkat(int, const char *, int, const char *, int);
int	 lockf(int, int, off_t);
off_t	 lseek(int, off_t, int);
long	 pathconf(const char *, int);
int	 pause(void);
int	 pipe(int [2]);
ssize_t	 pread(int, void *, size_t, off_t);
ssize_t	 pwrite(int, const void *, size_t, off_t);
ssize_t	 read(int, void *, size_t);
ssize_t	 readlink(const char *restrict, char *restrict, size_t);
ssize_t	 readlinkat(int, const char *restrict, char *restrict, size_t);
int	 rmdir(const char *);
int	 setegid(gid_t);
int	 seteuid(uid_t);
int	 setgid(gid_t);
int	 setpgid(pid_t, pid_t);
int	 setregid(gid_t, gid_t);
int	 setreuid(uid_t, uid_t);
pid_t	 setsid(void);
int	 setuid(uid_t);
unsigned sleep(unsigned);
int	 symlink(const char *, const char *);
int	 symlinkat(const char *, int, const char *);
void	 sync(void);
long	 sysconf(int);
pid_t	 tcgetpgrp(int);
int	 tcsetpgrp(int, pid_t);
int	 truncate(const char *, off_t);
char	*ttyname(int);
int	 ttyname_r(int, char *, size_t);
int	 unlink(const char *);
int	 unlinkat(int, const char *, int);
ssize_t	 write(int, const void *, size_t);
__END_DECLS

#endif /* !_UNISTD_H_ */
