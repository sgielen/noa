.PATH: ${.CURDIR}/string

SRCS+=	memchr.c memcmp.c memcpy.c memmove.c memset.c strcat.c \
	strchr.c strcmp.c strcpy.c strdup.c strlen.c strncat.c \
	strncmp.c strncpy.c strndup.c strnlen.c strpbrk.c strrchr.c \
	strtok.c strtok_r.c

SYMBOL_MAPS+=${.CURDIR}/string/Symbol.map
