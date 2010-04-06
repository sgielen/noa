.include <noa.sys.mk>

#CFLAGS+=-fpic

#LDFLAGS+=-Wl,--version-script=Version.map -nostdlib -shared -Wl,-x

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: kernel

kernel: ${OBJS}
	${CC} ${LDFLAGS} -o ${.TARGET} ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	@rm -f ${OBJS} ${CLEANFILES}
