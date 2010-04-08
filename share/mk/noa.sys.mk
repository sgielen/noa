.MAIN: all

CFLAGS+=-std=gnu99 -Wsystem-headers -Werror -Wall -Wno-format-y2k -W \
	-Wno-unused-parameter -Wstrict-prototypes -Wmissing-prototypes \
	-Wpointer-arith -Wreturn-type -Wwrite-strings -Wswitch \
	-Wshadow -Wunused-parameter -Wcast-align -Wchar-subscripts \
	-Winline -Wnested-externs -Wredundant-decls \
	-Wold-style-definition -Wno-pointer-sign -fomit-frame-pointer
