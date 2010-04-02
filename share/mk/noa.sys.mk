.MAIN: all

.if ${MACHINE} == "amd64"
MACHINE=x86_64
.elif ${MACHINE} == "i386"
MACHINE=x86_32
.endif

CFLAGS+=-nostdinc -std=gnu99 -Wsystem-headers -Werror -Wall \
	-Wno-format-y2k -W -Wno-unused-parameter -Wstrict-prototypes \
	-Wmissing-prototypes -Wpointer-arith -Wreturn-type -Wcast-qual \
	-Wwrite-strings -Wswitch -Wshadow -Wunused-parameter \
	-Wcast-align -Wchar-subscripts -Winline -Wnested-externs \
	-Wredundant-decls -Wold-style-definition -Wno-pointer-sign
