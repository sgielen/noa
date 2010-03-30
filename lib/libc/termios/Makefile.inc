.PATH: ${.CURDIR}/termios

SRCS+=	cfgetispeed.c cfgetospeed.c cfsetispeed.c cfsetospeed.c \
#	tcdrain.c tcflow.c tcflush.c tcgetattr.c tcgetsid.c \
#	tcsendbreak.c tcsetattr.c

SYMBOL_MAPS+=${.CURDIR}/termios/Symbol.map
