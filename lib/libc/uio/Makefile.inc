.PATH: ${.CURDIR}/uio

SRCS+=	preadv.c pwritev.c readv.c writev.c

SYMBOL_MAPS+=${.CURDIR}/uio/Symbol.map
