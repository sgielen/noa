.PATH: ${.CURDIR}/time

SRCS+=	gettimeofday.c nanosleep.c time.c utimes.c

SYMBOL_MAPS+=${.CURDIR}/time/Symbol.map
