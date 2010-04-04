.PATH: ${.CURDIR}/stat

SRCS+=	chmod.c fchmod.c fstat.c lstat.c mkdir.c mkfifo.c stat.c

SYMBOL_MAPS+=${.CURDIR}/stat/Symbol.map
