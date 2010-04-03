.PATH: ${.CURDIR}/string

SRCS+=	memchr.c memcmp.c memcpy.c memset.c strcat.c strchr.c strcmp.c \
	strcpy.c strdup.c strlen.c strncat.c strncmp.c strncpy.c \
	strnlen.c strpbrk.c strrchr.c strtok.c strtok_r.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
