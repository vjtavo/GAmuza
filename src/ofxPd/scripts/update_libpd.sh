#! /bin/bash

WD=$(dirname $0)

###

cd $WD

# get latest source
git clone git://gitorious.org/pdlib/libpd.git

# remove uneeded makefiles
find libpd -name "GNUmakefile.am" -delete
find libpd -name "Makefile.am" -delete
find libpd -name "makefile" -delete
rm libpd/pure-data/extra/makefile.subdir

# we dont need the java wrapper
rm libpd/libpd_wrapper/z_jni.c
rm libpd/libpd_wrapper/z_jni.h

# copy license
cp -v libpd/LICENSE.txt ../src/pd

# copy sources
cp -Rv libpd/pure-data ../src/pd
cp -Rv libpd/libpd_wrapper ../src/pd

# cleanup
rm -rfv libpd

