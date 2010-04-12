.PATH: ${.CURDIR}/fcntl

SRCS+=	creat.c open.c posix_fadvise.c

SYMBOL_MAPS+=${.CURDIR}/fcntl/Symbol.map
