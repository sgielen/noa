/*-
 * Copyright (c) 2010 The Noa Project, http://noaproject.org/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.	IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _STDLIB_H_
#define	_STDLIB_H_

#define	__NEED_NULL
#define	__NEED_DIV_T
#define	__NEED_LDIV_T
#define	__NEED_LLDIV_T
#define	__NEED_SIZE_T
#define	__NEED_WCHAR_T

#include <noa/cdefs.h>
#include <noa/types.h>

#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0
/* XXX */
#define	RAND_MAX	TODO_UNDEFINED

/* XXX constants as in sys/wait.h: WEXITSTATUS, etc */

__BEGIN_DECLS
void	 _Exit(int);
void	 abort(void);
int	 abs(int);
int	 atexit(void (*)(void));
double	 atof(const char *);
int	 atoi(const char *);
long	 atol(const char *);
long long	atoll(const char *);
void	*bsearch(const void *, const void *, size_t, size_t,
	         int (*)(const void *, const void *));
void	*calloc(size_t, size_t);
div_t	 div(int, int);
void	 exit(int);
void	 free(void *);
char	*getenv(const char *);
int	 getsubopt(char **, char *const *, char **);
int	 grantpt(int);
long	 labs(long);
ldiv_t	 ldiv(long, long);
long long	 llabs(long long);
lldiv_t	 lldiv(long long, long long);
void	*malloc(size_t);
int	 mblen(const char *, size_t);
size_t	 mbstowcs(wchar_t *restrict, const char *restrict, size_t);
int	 mbtowc(wchar_t *restrict, const char *restrict, size_t);
char	*mkdtemp(char *);
int	 mkstemp(char *);
int	 posix_memalign(void **, size_t, size_t);
int	 posix_openpt(int);
char	*ptsname(int);
void	 qsort(void *, size_t, size_t, int (*)(const void *,
	        const void *));
int	 rand(void);
void	*realloc(void *, size_t);
char	*realpath(const char *restrict, char *restrict);
int	 setenv(const char *, const char *, int);
void	 srand(unsigned);
double	 strtod(const char *restrict, char **restrict);
float	 strtof(const char *restrict, char **restrict);
long	 strtol(const char *restrict, char **restrict, int);
long double	 strtold(const char *restrict, char **restrict);
long long	 strtoll(const char *restrict, char **restrict, int);
unsigned long	 strtoul(const char *restrict, char **restrict, int);
unsigned long long
	 strtoull(const char *restrict, char **restrict, int);
int	 system(const char *);
int	 unlockpt(int);
int	 unsetenv(const char *);
size_t	 wcstombs(char *restrict, const wchar_t *restrict, size_t);
int	 wctomb(char *, wchar_t);
__END_DECLS

#endif /* !_STDLIB_H_ */
