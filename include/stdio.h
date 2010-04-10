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

#ifndef _STDIO_H_
#define	_STDIO_H_

#define	__NEED_OFF_T
#define	__NEED_SIZE_T
#define	__NEED_SSIZE_T
#define	__NEED_VA_LIST

#include <noa/types.h>

/* XXX: <unistd.h>. */
#ifndef SEEK_CUR
#define	SEEK_CUR	1
#define	SEEK_END	2
#define	SEEK_SET	3
#endif

typedef struct __FILE FILE;
typedef off_t fpos_t;

__BEGIN_DECLS
extern FILE *stderr;
extern FILE *stdin;
extern FILE *stdout;

void	 clearerr(FILE *);
char	*ctermid(char *);
int	 dprintf(int, const char *restrict, ...);
int	 fclose(FILE *);
FILE	*fdopen(int, const char *);
int	 feof(FILE *);
int	 ferror(FILE *);
int	 fflush(FILE *);
int	 fgetc(FILE *);
int	 fgetpos(FILE *restrict, fpos_t *restrict);
char	*fgets(char *restrict, int, FILE *restrict);
int	 fileno(FILE *);
void	 flockfile(FILE *);
FILE	*fmemopen(void *restrict, size_t, const char *restrict);
FILE	*fopen(const char *restrict, const char *restrict);
int	 fprintf(FILE *restrict, const char *restrict, ...);
int	 fputc(int, FILE *);
int	 fputs(const char *restrict, FILE *restrict);
size_t	 fread(void *restrict, size_t, size_t, FILE *restrict);
FILE	*freopen(const char *restrict, const char *restrict, FILE *restrict);
int	 fscanf(FILE *restrict, const char *restrict, ...);
int	 fseek(FILE *, long, int);
int	 fseeko(FILE *, off_t, int);
int	 fsetpos(FILE *, const fpos_t *);
long	 ftell(FILE *);
off_t	 ftello(FILE *);
int	 ftrylockfile(FILE *);
void	 funlockfile(FILE *);
size_t	 fwrite(const void *restrict, size_t, size_t, FILE *restrict);
int	 getc(FILE *);
int	 getchar(void);
int	 getc_unlocked(FILE *);
int	 getchar_unlocked(void);
ssize_t	 getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t	 getline(char **restrict, size_t *restrict, FILE *restrict);
FILE	*open_memstream(char **, size_t *);
int	 pclose(FILE *);
void	 perror(const char *);
FILE	*popen(const char *, const char *);
int	 printf(const char *restrict, ...);
int	 putc(int, FILE *);
int	 putchar(int);
int	 putc_unlocked(int, FILE *);
int	 putchar_unlocked(int);
int	 puts(const char *);
int	 remove(const char *);
int	 rename(const char *, const char *);
int	 renameat(int, const char *, int, const char *);
void	 rewind(FILE *);
int	 scanf(const char *restrict, ...);
void	 setbuf(FILE *restrict, char *restrict);
int	 setvbuf(FILE *restrict, char *restrict, int, size_t);
int	 snprintf(char *restrict, size_t, const char *restrict, ...);
int	 sprintf(char *restrict, const char *restrict, ...);
int	 sscanf(const char *restrict, const char *restrict, ...);
FILE	*tmpfile(void);
int	 ungetc(int, FILE *);
int	 vdprintf(int, const char *restrict, va_list);
int	 vfprintf(FILE *restrict, const char *restrict, va_list);
int	 vfscanf(FILE *restrict, const char *restrict, va_list);
int	 vprintf(const char *restrict, va_list);
int	 vscanf(const char *restrict, va_list);
int	 vsnprintf(char *restrict, size_t, const char *restrict, va_list);
int	 vsprintf(char *restrict, const char *restrict, va_list);
int	 vsscanf(const char *restrict, const char *restrict, va_list);
__END_DECLS

#endif /* !_STDIO_H_ */
