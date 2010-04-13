.include <noa.sys.mk>

CFLAGS+=-D_KERNEL -fpic
LD=ld
LDFLAGS+=-warn-common -X -T ${.CURDIR}/ldscript.${MACHINE}

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: kernel

kernel: ${OBJS}
	${LD} ${LDFLAGS} -o ${.TARGET} ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	@rm -f ${OBJS} ${CLEANFILES}
