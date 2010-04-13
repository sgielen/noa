.include <noa.sys.mk>

CFLAGS+=-D_KERNEL
LD=ld
LDFLAGS+=-e kinit -warn-common -X --image-base 0xffffffff80000000

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: kernel

kernel: ${OBJS}
	${LD} ${LDFLAGS} -o ${.TARGET} ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	@rm -f ${OBJS} ${CLEANFILES}
