# --------------------------------------------------------

# --------------------------------------------------------
# OF_ROOT allows to move projects outside apps/* just set this variable to the
# absoulte path to the OF root folder
# --------------------------------------------------------

OF_ROOT = ../../..

# --------------------------------------------------------
# USER_CFLAGS allows to pass custom flags to the compiler
# for example search paths
# --------------------------------------------------------

# KISS FFT
USER_CFLAGS = -I src/ofxFft/libs/kiss

# BOOST
USER_CFLAGS += -I ../../../libs/boost/include/boost

# BULLET PHYSICS
USER_CFLAGS += -I ../../../addons/ofxBullet/src
USER_CFLAGS += -I ../../../addons/ofxBullet/bullet/include
USER_CFLAGS += -I ../../../addons/ofxBullet/bullet/include/BulletCollision/CollisionShapes

# LUA
USER_CFLAGS += -I ../../../addons/ofxLua/src
USER_CFLAGS += -I ../../../addons/ofxLua/src/lua
USER_CFLAGS += -I ../../../addons/ofxLua/src/luabind

# OPENNI
USER_CFLAGS += -I src/ofxOpenNI/src
USER_CFLAGS += -I src/ofxOpenNI/include
USER_CFLAGS += -I /usr/include/ni
USER_CFLAGS += -I /usr/include/nite

# GAmuza
USER_CFLAGS += -I src
USER_CFLAGS += -I src/ofxArcText/src
USER_CFLAGS += -I src/ofxAudioSample/src
USER_CFLAGS += -I src/ofxAudioSample/libs/libsndfile/include
USER_CFLAGS += -I src/ofxChromaKey/src
USER_CFLAGS += -I src/ofxCLD/src
USER_CFLAGS += -I src/ofxControlPanel/src
USER_CFLAGS += -I src/ofxCvKalman
USER_CFLAGS += -I src/ofxDither/src
USER_CFLAGS += -I src/ofxDmx/src
USER_CFLAGS += -I src/ofxFft/src
USER_CFLAGS += -I src/ofxFileDialog/src
USER_CFLAGS += -I src/ofxFTGL/src
USER_CFLAGS += -I src/ofxFTGL/libs
USER_CFLAGS += -I src/ofxFTGL/libs/FTGL/src
USER_CFLAGS += -I src/ofxFX/src
USER_CFLAGS += -I src/ofxGamuza/src/audioAnalysis
USER_CFLAGS += -I src/ofxGamuza/src/audioSample
USER_CFLAGS += -I src/ofxGamuza/src/audioSequencing
USER_CFLAGS += -I src/ofxGamuza/src/audioSynthesis
USER_CFLAGS += -I src/ofxGamuza/src/gamuza
USER_CFLAGS += -I src/ofxGamuza/src/gui
USER_CFLAGS += -I src/ofxGamuza/src/imageAnalysis
USER_CFLAGS += -I src/ofxGamuza/src/math
USER_CFLAGS += -I src/ofxGamuza/src/midiUtils
USER_CFLAGS += -I src/ofxGamuza/src/randomUtils
USER_CFLAGS += -I src/ofxGamuza/src/sourceTracking
USER_CFLAGS += -I src/ofxGaussian/src/
USER_CFLAGS += -I src/ofxGLEditor/src
USER_CFLAGS += -I src/ofxHalftoner/src
USER_CFLAGS += -I src/ofxKeyMap/src
USER_CFLAGS += -I src/ofxLibsndfileRecorder/src
USER_CFLAGS += -I src/ofxLogicMachine/src
USER_CFLAGS += -I src/ofxMemoryUsage/src
USER_CFLAGS += -I src/ofxMidi/src
USER_CFLAGS += -I src/ofxMidi/libs
USER_CFLAGS += -I src/ofxMissing/src
USER_CFLAGS += -I src/ofxOpenCVBlobTrackingExt/src
USER_CFLAGS += -I src/ofxPd/src
USER_CFLAGS += -I src/ofxPd/src/pd/libpd_wrapper
USER_CFLAGS += -I src/ofxPd/src/pd/pure-data/src
USER_CFLAGS += -I src/ofxRange/src
USER_CFLAGS += -I src/ofxSkyBox/src
USER_CFLAGS += -I src/ofxSlitScan/src
USER_CFLAGS += -I src/ofxStringEncoders/src
USER_CFLAGS += -I src/ofxSubtitles/src
USER_CFLAGS += -I src/ofxTextInputField/src
USER_CFLAGS += -I src/ofxTimeline/src
USER_CFLAGS += -I src/ofxTween/src
USER_CFLAGS += -I src/ofxTween/src/Easings
USER_CFLAGS += -I src/ofxTwitterStream/src
USER_CFLAGS += -I src/ofxTwitterStream/src/lib/jansson
USER_CFLAGS += -I src/ofxTwitterStream/src/lib/stringencoders
USER_CFLAGS += -I src/ofxVideoRecorder/src
USER_CFLAGS += -I src/ofxVoronoiGL/src
USER_CFLAGS += -I src/ofxWordPalette/src

# OFXPD
USER_CFLAGS += -DHAVE_UNISTD_H -DUSEAPI_DUMMY -DPD -shared

# --------------------------------------------------------
# USER_LDFLAGS allows to pass custom flags to the linker
# --------------------------------------------------------

# BULLET PHYSICS
USER_LDFLAGS = ../../../addons/ofxBullet/bullet/lib/linux/Release/libBulletDynamics.a ../../../addons/ofxBullet/bullet/lib/linux/Release/libBulletCollision.a  ../../../addons/ofxBullet/bullet/lib/linux/Release/libBulletSoftBody.a ../../../addons/ofxBullet/bullet/lib/linux/Release/libLinearMath.a ../../../addons/ofxBullet/bullet/lib/linux/Release/libMiniCL.a

# LUA
USER_LDFLAGS += ../../../addons/ofxLua/lib/linux/ofxLuaStaticLib/liblua.a
USER_LDFLAGS += ../../../addons/ofxLua/lib/linux/ofxLuabindStaticLib/libluabind.a

# LIBSNDFILE
USER_LDFLAGS += src/ofxAudioSample/libs/libsndfile/lib/linux/libsndfile.a

# OPENNI
USER_LDFLAGS += /usr/lib/libnimCodecs.so /usr/lib/libnimMockNodes.so /usr/lib/libnimRecorder.so /usr/lib/libXnCore.so /usr/lib/libXnDDK.so /usr/lib/libXnDeviceFile.so /usr/lib/libXnDeviceSensorV2.so /usr/lib/libXnFormats.so /usr/lib/libXnVFeatures_1_4_1.so /usr/lib/libXnVHandGenerator_1_4_1.so /usr/lib/libXnVNite_1_4_1.so /usr/lib/libOpenNI.so

# OFXPD
USER_LDFLAGS += --export-dynamic

# --------------------------------------------------------
# use this to add system libraries for example:
# USER_LIBS = -lpango
# --------------------------------------------------------

# OPENNI
USER_LIBS  = -lusb-1.0
USER_LIBS += -lOpenNI

# X11
USER_LIBS += -lX11

# OFXPD
USER_LIBS += -ldl -lm

# ofxFTGLFont
USER_LIBS += -lftgl

# --------------------------------------------------------
# change this to add different compiler optimizations to your project

LINUX_COMPILER_OPTIMIZATION = -march=native -mtune=native -Os

ANDROID_COMPILER_OPTIMIZATION = -Os

# you shouldn't need to change this for usual OF apps, it allows to include code from other directories
# useful if you need to share a folder with code between 2 apps. The makefile will search recursively
# you can only set 1 path here

USER_SOURCE_DIR =

# you shouldn't need to change this for usual OF apps, it allows to exclude code from some directories
# useful if you have some code for reference in the project folder but don't want it to be compiled

EXCLUDE_FROM_SOURCE="bin,.xcodeproj,obj"

# --------------------------------------------------------
