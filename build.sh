#!/bin/sh

set -e

export CFLAGS='-O3 -I../../include -I../../include/machdep/${MACHINE}'
make -C lib/libc -m ../../share/mk $1
