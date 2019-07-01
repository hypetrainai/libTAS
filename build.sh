#!/bin/sh

set -e
cd "$(dirname "$0")"

libtoolize
aclocal
autoconf
autoheader
automake --add-missing
./configure "$@"
make -j4
mkdir -p build64
cp -f src/program/libTAS src/program/pylibtas.py src/program/.libs/_pylibtas.so src/library/.libs/libtas.so build64
cp -f build64/pylibtas.py build64/_pylibtas.so ..
