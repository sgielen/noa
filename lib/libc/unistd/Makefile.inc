.PATH: ${.CURDIR}/unistd

SRCS+=	dup.c fchown.c isatty.c read.c readv.c write.c writev.c

SYMBOL_MAPS+=${.CURDIR}/unistd/Symbol.map
