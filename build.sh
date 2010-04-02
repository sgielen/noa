#!/bin/sh

set -e

HERE="`realpath .`"
export CFLAGS="-O3 -nostdinc -I$HERE/include -I$HERE/include/machdep/\${MACHINE}"
make -C lib/libc -m ../../share/mk $1
