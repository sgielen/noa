#!/bin/sh

set -e

HERE="`realpath .`"
export CFLAGS="-O3 -nostdinc -I$HERE/include -I$HERE/include/machdep/\${MACHINE}"
SHAREMK="`realpath share/mk`"
make -C lib/libc -m $SHAREMK $1