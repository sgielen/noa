#!/bin/sh

set -e

make -C lib/libc -m ../../share/mk $1
