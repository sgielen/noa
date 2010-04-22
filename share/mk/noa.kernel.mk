.include <noa.sys.mk>

CFLAGS+=-D_KERNEL -fpic -ffreestanding
LD=ld
LDFLAGS+=-warn-common -X -T ${.CURDIR}/ldscript.${MACHINE}

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: kernel

kernel: ${OBJS}
	@echo LD ${.TARGET}
	@${LD} ${LDFLAGS} -o ${.TARGET} ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	@rm -f kernel ${OBJS} ${CLEANFILES}
