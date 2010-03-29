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

#ifndef _STRING_H_
#define	_STRING_H_

#define	__NEED_LOCALE_T
#define	__NEED_NULL
#define	__NEED_SIZE_T

#include <noa/cdefs.h>
#include <noa/types.h>

__BEGIN_DECLS
void	*memchr(const void *, int, size_t);
int	 memcmp(const void *, const void *, size_t);
void	*memcpy(void *restrict, const void *restrict, size_t);
void	*memmove(void *, const void *, size_t);
void	*memset(void *, int, size_t);
char	*stpcpy(char *restrict, const char *restrict);
char	*stpncpy(char *restrict, const char *restrict, size_t);
char	*strcat(char *restrict, const char *restrict);
char	*strchr(const char *, int);
int	 strcmp(const char *, const char *);
int	 strcoll(const char *, const char *);
int	 strcoll_l(const char *, const char *, locale_t);
char	*strcpy(char *restrict, const char *restrict);
size_t	 strcspn(const char *, const char *);
char	*strdup(const char *);
char	*strerror(int);
char	*strerror_l(int, locale_t);
int	 strerror_r(int, char *, size_t);
size_t	 strlen(const char *);
char	*strncat(char *restrict, const char *restrict, size_t);
int	 strncmp(const char *, const char *, size_t);
char	*strncpy(char *restrict, const char *restrict, size_t);
char	*strndup(const char *, size_t);
size_t	 strnlen(const char *, size_t);
char	*strpbrk(const char *, const char *);
char	*strrchr(const char *, int);
char	*strsignal(int);
size_t	 strspn(const char *, const char *);
char	*strstr(const char *, const char *);
char	*strtok(char *restrict, const char *restrict);
char	*strtok_r(char *restrict, const char *restrict, char **restrict);
size_t	 strxfrm(char *restrict, const char *restrict, size_t);
size_t	 strxfrm_l(char *restrict, const char *restrict, size_t, locale_t);
__END_DECLS

#endif /* !_STRING_H_ */
