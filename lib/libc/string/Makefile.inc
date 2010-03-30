.PATH: ${.CURDIR}/string

SRCS+=	strcat.c strcmp.c strcpy.c strdup.c strlen.c strncat.c strncmp.c
SRCS+=	memchr.c memcmp.c memcpy.c memset.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
