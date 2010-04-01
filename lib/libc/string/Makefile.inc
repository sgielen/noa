.PATH: ${.CURDIR}/string

SRCS+=	strcat.c strchr.c strcpy.c strdup.c strlen.c memchr.c memcmp.c \
	memcpy.c memset.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
