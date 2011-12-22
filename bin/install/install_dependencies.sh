#!/bin/bash

apt-get remove ffmpeg x264 libx264-dev
apt-get update
apt-get install build-essential checkinstall git libfaac-dev libjack-jackd2-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libsdl1.2-dev libtheora-dev libva-dev libvdpau-dev libvorbis-dev libx11-dev libxfixes-dev texi2html yasm zlib1g-dev libmpg123-dev gstreamer0.10-plugins-ugly libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libavcodec-dev libavformat-dev libavutil-dev libswscale-dev freeglut3-dev libasound2-dev libxmu-dev libxxf86vm-dev g++ libgl1-mesa-dev libglu1-mesa-dev libraw1394-dev libudev-dev libdrm-dev gstreamer0.10-ffmpeg libglew1.5-dev libopenal-dev libsndfile-dev libfreeimage-dev libcairo2-dev libgtk2.0-dev python-lxml python-argparse ffmpeg libsndfile1 libsndfile1-dev
git clone git://git.videolan.org/x264
cd x264
./configure --enable-static
make
sudo checkinstall --pkgname=x264 --pkgversion="3:$(./version.sh | awk -F'[" ]' '/POINT/{print $4"+git"$5}')" --backup=no --deldoc=yes --fstrans=no --default
cd ..
git clone --depth 1 git://source.ffmpeg.org/ffmpeg
cd ffmpeg
./configure --enable-gpl --enable-libfaac --enable-libmp3lame --enable-libopencore-amrnb --enable-libopencore-amrwb --enable-libtheora --enable-libvorbis --enable-libx264 --enable-nonfree --enable-postproc --enable-version3 --enable-x11grab
make
sudo checkinstall --pkgname=ffmpeg --pkgversion="5:$(date +%Y%m%d%H%M)-git" --backup=no --deldoc=yes --fstrans=no --default
hash x264 ffmpeg ffplay ffprobe
make tools/qt-faststart
sudo checkinstall --pkgname=qt-faststart --pkgversion="$(date +%Y%m%d%H%M)-git" --backup=no --deldoc=yes --fstrans=no --default install -Dm755 tools/qt-faststart /usr/local/bin/qt-faststart
cd ..
cd x264
make distclean
./configure --enable-static
make
sudo checkinstall --pkgname=x264 --pkgversion="3:$(./version.sh | awk -F'[" ]' '/POINT/{print $4"+git"$5}')" --backup=no --deldoc=yes --fstrans=no --default
cd ..
sudo rm -r ffmpeg
sudo rm -r x264
cd ffmpeg_presets
sudo cp * /usr/local/share/ffmpeg/
cd ..

