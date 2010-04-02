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

#ifndef _CTYPE_H_
#define	_CTYPE_H_

#define	__NEED_LOCALE_T

#include <noa/types.h>

__BEGIN_DECLS
int	 isalnum(int);
int	 isalnum_l(int, locale_t);
int	 isalpha(int);
int	 isalpha_l(int, locale_t);
int	 isblank(int);
int	 isblank_l(int, locale_t);
int	 iscntrl(int);
int	 iscntrl_l(int, locale_t);
int	 isdigit(int);
int	 isdigit_l(int, locale_t);
int	 isgraph(int);
int	 isgraph_l(int, locale_t);
int	 islower(int);
int	 islower_l(int, locale_t);
int	 isprint(int);
int	 isprint_l(int, locale_t);
int	 ispunct(int);
int	 ispunct_l(int, locale_t);
int	 isspace(int);
int	 isspace_l(int, locale_t);
int	 isupper(int);
int	 isupper_l(int, locale_t);
int	 isxdigit(int);
int	 isxdigit_l(int, locale_t);
int	 tolower(int);
int	 tolower_l(int, locale_t);
int	 toupper(int);
int	 toupper_l(int, locale_t);
__END_DECLS

#endif /* !_CTYPE_H_ */
