#!/bin/sh

set -e

MAKE="bsdmake"
HERE="`realpath .`"
export CFLAGS="-O3 -nostdinc -I$HERE/include -I$HERE/include/machdep/\${MACHINE}"
SHAREMK="`realpath share/mk`"
$MAKE -m $SHAREMK "$@"
