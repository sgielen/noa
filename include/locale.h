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

#ifndef _LOCALE_H_
#define	_LOCALE_H_

#define	__NEED_LOCALE_T
#define	__NEED_NULL

#include <noa/types.h>

__ABI_STRUCT(locale, 128, {
	char	*currency_symbol;
	char	*decimal_point;
	char	 frac_digits;
	char	*grouping;
	char	*int_curr_symbol;
	char	 int_frac_digits;
	char	 int_n_cs_precedes;
	char	 int_n_sep_by_space;
	char	 int_n_sign_posn;
	char	 int_p_cs_precedes;
	char	 int_p_sep_by_space;
	char	 int_p_sign_posn;
	char	*mon_decimal_point;
	char	*mon_grouping;
	char	*mon_thousands_sep;
	char	*negative_sign;
	char	 n_cs_precedes;
	char	 n_sep_by_space;
	char	 n_sign_posn;
	char	*positive_sign;
	char	 p_cs_precedes;
	char	 p_sep_by_space;
	char	 p_sign_posn;
	char	*thousands_sep;
})

#define	LC_COLLATE		0x00000001
#define	LC_CTYPE		0x00000002
#define	LC_MESSAGES		0x00000004
#define	LC_MONETARY		0x00000008
#define	LC_NUMERIC		0x00000010
#define	LC_TIME			0x00000020
#define	LC_ALL			0xffffffff

#define	LC_COLLATE_MASK		LC_COLLATE
#define	LC_CTYPE_MASK		LC_CTYPE
#define	LC_MESSAGES_MASK	LC_MESSAGES
#define	LC_MONETARY_MASK	LC_MONETARY
#define	LC_NUMERIC_MASK		LC_NUMERIC
#define	LC_TIME_MASK		LC_TIME
#define	LC_ALL_MASK		LC_ALL

#define	LC_GLOBAL_LOCALE	(locale_t)-1

__BEGIN_DECLS
locale_t duplocale(locale_t);
void	 freelocale(locale_t);
struct lconv *
	 localeconv(void);
locale_t newlocale(int, const char *, locale_t);
char	*setlocale(int, const char *);
locale_t uselocale(locale_t);
__END_DECLS

#endif /* !_LOCALE_H_ */
