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

#ifndef _TIME_H_
#define	_TIME_H_

#define	__NEED_CLOCKID_T
#define	__NEED_CLOCK_T
#define	__NEED_NULL
#define	__NEED_PID_T
#define	__NEED_SIZE_T
#define	__NEED_STRUCT_TIMESPEC
#define	__NEED_TIMER_T
#define	__NEED_TIME_T

#include <noa/cdefs.h>
#include <noa/types.h>

struct sigevent;

struct tm {
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};

struct itimerspec {
	struct timespec	it_interval;
	struct timespec	it_value;
};

__BEGIN_DECLS
clock_t	 clock(void);
int	 clock_getres(clockid_t, struct timespec *);
int	 clock_gettime(clockid_t, struct timespec *);
int	 clock_nanosleep(clockid_t, int, const struct timespec *,
	     struct timespec *);
int	 clock_settime(clockid_t, const struct timespec *);
double	 difftime(time_t, time_t);
struct tm *
	 gmtime(const time_t *);
struct tm *
	 gmtime_r(const time_t *restrict, struct tm *restrict);
struct tm *
	 localtime(const time_t *);
struct tm *
	 localtime_r(const time_t *restrict, struct tm *restrict);
time_t	 mktime(struct tm *);
int	 nanosleep(const struct timespec *, struct timespec *);
size_t	 strftime(char *restrict, size_t, const char *restrict,
	     const struct tm *restrict);
size_t	 strftime_l(char *restrict, size_t, const char *restrict,
	     const struct tm *restrict, locale_t);
time_t	 time(time_t *);
int	 timer_create(clockid_t, struct sigevent *restrict,
	     timer_t *restrict);
int	 timer_delete(timer_t);
int	 timer_getoverrun(timer_t);
int	 timer_gettime(timer_t, struct itimerspec *);
int	 timer_settime(timer_t, int, const struct itimerspec *restrict,
	     struct itimerspec *restrict);
void	 tzset(void);
__END_DECLS

#endif /* !_TIME_H_ */
