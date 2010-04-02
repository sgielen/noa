.include <noa.sys.mk>

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: lib${LIB}.so

lib${LIB}.so: ${OBJS}

${OBJS}: ${SRCS:M*.h}

clean:
	rm -f ${OBJS} ${CLEANFILES}
