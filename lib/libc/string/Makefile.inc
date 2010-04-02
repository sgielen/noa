.PATH: ${.CURDIR}/string

SRCS+=	memchr.c memcmp.c memcpy.c memset.c strcat.c strchr.c strcmp.c \
	strcpy.c strdup.c strlen.c strncat.c strncmp.c strnlen.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
