.PATH: ${.CURDIR}/termios

SRCS+=	cfgetispeed.c cfgetospeed.c cfsetispeed.c cfsetospeed.c \
	tcdrain.c tcflush.c tcgetattr.c tcgetsid.c tcsetattr.c
#SRCS+=	tcflow.c tcsendbreak.c

SYMBOL_MAPS+=${.CURDIR}/termios/Symbol.map
