.include <noa.sys.mk>

#CFLAGS+=-fpic

LD=ld
LDFLAGS+=-Bdynamic -warn-common -export-dynamic -dynamic-linker /red/herring
LDFLAGS+=-X

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: kernel

kernel: ${OBJS}
	${LD} ${LDFLAGS} -o ${.TARGET} ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	@rm -f ${OBJS} ${CLEANFILES}
