.PATH: ${.CURDIR}/locale

SRCS+=	uselocale.c

CFLAGS+=-I${.CURDIR}/locale

SYMBOL_MAPS+=${.CURDIR}/locale/Symbol.map
