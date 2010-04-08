.PATH: ${.CURDIR}/socket

SRCS+=	recv.c send.c

SYMBOL_MAPS+=${.CURDIR}/socket/Symbol.map
