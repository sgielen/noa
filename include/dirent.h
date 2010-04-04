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

#ifndef _DIRENT_H_
#define	_DIRENT_H_

#define	__NEED_INO_T

#include <noa/types.h>

typedef struct __DIR DIR;

__ABI_STRUCT(dirent, 64, {
	ino_t	d_ino;
	char	d_name[32];
})

__BEGIN_DECLS
int	 alphasort(const struct dirent **, const struct dirent **);
int	 closedir(DIR *);
int	 dirfd(DIR *);
DIR	*fdopendir(int);
DIR	*opendir(const char *);
struct dirent *
	 readdir(DIR *);
int	 readdir_r(DIR *restrict, struct dirent *restrict,
	     struct dirent **restrict);
void	 rewinddir(DIR *);
int	 scandir(const char *, struct dirent ***,
	     int (*)(const struct dirent *),
	     int (*)(const struct dirent **, const struct dirent **));
__END_DECLS

#endif /* !_DIRENT_H_ */
