.PATH: ${.CURDIR}/time

SRCS+=	difftime.c gettimeofday.c gmtime.c localtime.c nanosleep.c \
	time.c utimes.c

SYMBOL_MAPS+=${.CURDIR}/time/Symbol.map
