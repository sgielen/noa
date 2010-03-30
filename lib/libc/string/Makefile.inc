.PATH: ${.CURDIR}/string

SRCS+=	strdup.c strlen.c memchr.c memcmp.c memcpy.c memset.c strcpy.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
