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

#ifndef _COMPLEX_H_
#define	_COMPLEX_H_

#include <noa/cdefs.h>

#define	complex		_Complex
#define	_Complex_I	1.0fi
#define	I		_Complex_I

__BEGIN_DECLS
double	 ccabs(double complex);
float	 ccabsf(float complex);
long double
	 ccabsl(long double complex);
double complex
	 ccacos(double complex);
float complex
	 ccacosf(float complex);
double complex
	 ccacosh(double complex);
float complex
	 ccacoshf(float complex);
long double complex
	 ccacoshl(long double complex);
long double complex
	 ccacosl(long double complex);
double	 ccarg(double complex);
float	 ccargf(float complex);
long double
	 ccargl(long double complex);
double complex
	 ccasin(double complex);
float complex
	 ccasinf(float complex);
double complex
	 ccasinh(double complex);
float complex
	 ccasinhf(float complex);
long double complex
	 ccasinhl(long double complex);
long double complex
	 ccasinl(long double complex);
double complex
	 ccatan(double complex);
float complex
	 ccatanf(float complex);
double complex
	 ccatanh(double complex);
float complex
	 ccatanhf(float complex);
long double complex
	 ccatanhl(long double complex);
long double complex
	 ccatanl(long double complex);
double complex
	 cccos(double complex);
float complex
	 cccosf(float complex);
double complex
	 cccosh(double complex);
float complex
	 cccoshf(float complex);
long double complex
	 cccoshl(long double complex);
long double complex
	 cccosl(long double complex);
double complex
	 ccexp(double complex);
float complex
	 ccexpf(float complex);
long double complex
	 ccexpl(long double complex);
double	 ccimag(double complex);
float	 ccimagf(float complex);
long double
	 ccimagl(long double complex);
double complex
	 cclog(double complex);
float complex
	 cclogf(float complex);
long double complex
	 cclogl(long double complex);
double complex
	 cconj(double complex);
float complex
	 cconjf(float complex);
long double complex
	 cconjl(long double complex);
double complex
	 ccpow(double complex, double complex);
float complex
	 ccpowf(float complex, float complex);
long double complex
	 ccpowl(long double complex, long double complex);
double complex
	 ccproj(double complex);
float complex
	 ccprojf(float complex);
long double complex
	 ccprojl(long double complex);
double	 ccreal(double complex);
float	 ccrealf(float complex);
long double
	 ccreall(long double complex);
double complex
	 ccsin(double complex);
float complex
	 ccsinf(float complex);
double complex
	 ccsinh(double complex);
float complex
	 ccsinhf(float complex);
long double complex
	 ccsinhl(long double complex);
long double complex
	 ccsinl(long double complex);
double complex
	 ccsqrt(double complex);
float complex
	 ccsqrtf(float complex);
long double complex
	 ccsqrtl(long double complex);
double complex
	 cctan(double complex);
float complex
	 cctanf(float complex);
double complex
	 cctanh(double complex);
float complex
	 cctanhf(float complex);
long double complex
	 cctanhl(long double complex);
long double complex
	 cctanl(long double complex);
__END_DECLS

#endif /* !_COMPLEX_H_ */
