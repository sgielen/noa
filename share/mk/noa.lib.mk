.include <noa.sys.mk>

OBJS+=	${SRCS:N*.h:R:S/$/.o/}

all: lib${LIB}.so

lib${LIB}.so: ${OBJS}

clean:
	rm -f ${OBJS} ${CLEANFILES}
