.PATH: ${.CURDIR}/unistd

SRCS+=	read.c readv.c write.c writev.c

SYMBOL_MAPS+=${.CURDIR}/unistd/Symbol.map
