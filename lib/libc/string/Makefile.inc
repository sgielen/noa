.PATH: ${.CURDIR}/string

SRCS+=	strcat.c strcpy.c strdup.c strlen.c memchr.c memcmp.c memcpy.c
SRCS+=	memset.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
