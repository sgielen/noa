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

#include <assert.h>
#include <kernel.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

static const char hex[16] = "0123456789abcdef";

static inline void
putnumber(uintmax_t i, unsigned int base)
{
	uintmax_t m;

	assert(base >= 2 && base <= 16 && "Invalid base");
	for (m = 1; (i / m) >= base; m *= base);
	for (; m >= 1; m /= base)
		putchar(hex[(i / m) % base]);
}

static inline void
putstring(const char *str)
{

	while (*str != '\0')
		putchar(*str++);
}

#define	VA_GET(cast, sign) \
	(numsize == sizeof(char) ? (cast)va_arg(args, sign char) :	\
	(numsize == sizeof(short) ? (cast)va_arg(args, sign short) :	\
	(numsize == sizeof(int) ? (cast)va_arg(args, sign int) :	\
	(numsize == sizeof(long) ? (cast)va_arg(args, sign long) :	\
	((cast)va_arg(args, sign long long))))))
#define	VA_SIGNED	VA_GET(intmax_t, signed)
#define	VA_UNSIGNED	VA_GET(uintmax_t, unsigned)

void
printf(const char *restrict format, ...)
{
	va_list args;
	const char *str;
	int state = 0;
	intmax_t si;
	uintmax_t ui;
	size_t numsize;
	char c;

	va_start(args, format);
	for (; *format != '\0'; format++) {
		if (state == 0) {
			if (*format == '%') {
				state = 1;
				numsize = sizeof(int);
			} else
				putchar(*format);
		} else {
			switch (*format) {
			case '%':
				putchar('%');
				state = 0;
				break;
			case 'c':
				c = va_arg(args, char);
				putchar(c);
				state = 0;
				break;
			case 'd':
				si = VA_SIGNED;
				if (si < 0) {
					putchar('-');
					putnumber(-si, 10);
				} else {
					putnumber(si, 10);
				}
				state = 0;
				break;
			case 'h':
				numsize = (numsize == sizeof(short)) ?
				    sizeof(char) : sizeof(short);
				break;
			case 'j':
				numsize = sizeof(intmax_t);
				break;
			case 'l':
				numsize = (numsize == sizeof(long)) ?
				    sizeof(long long) : sizeof(long);
				break;
			case 'o':
				ui = VA_UNSIGNED;
				putnumber(ui, 8);
				state = 0;
				break;
			case 'p':
				ui = VA_UNSIGNED;
				putnumber(ui, 16);
				state = 0;
				break;
			case 's':
				str = va_arg(args, const char *);
				putstring(str);
				state = 0;
				break;
			case 't':
				numsize = sizeof(ptrdiff_t);
				break;
			case 'u':
				ui = VA_UNSIGNED;
				putnumber(ui, 10);
				state = 0;
				break;
			case 'x':
				ui = VA_UNSIGNED;
				putnumber(ui, 16);
				state = 0;
				break;
			case 'z':
				numsize = sizeof(size_t);
				break;
			default:
				assert(0 && "Invalid printf modifier");
			}
		}
	}
	va_end(args);
}
