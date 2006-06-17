INCLUDES=-I$(top_srcdir)/include 

lib_LTLIBRARIES = libSILLY.la
libSILLY_la_CXXFLAGS= 
libSILLY_la_LIBADD=
libSILLY_la_LDFLAGS= -version-info @SILLY_VERSION_INFO@
libSILLY_la_SOURCES= \
  SILLYDataSource.cpp \
  SILLYMemoryDataSource.cpp \
  SILLYImageLoader.cpp \
  SILLYImageLoaderManager.cpp \
  SILLYImageContext.cpp \
  SILLYImage.cpp \
  loaders/SILLYTGAImageLoader.cpp \
  loaders/SILLYTGAImageContext.cpp 



if SILLY_HAVE_JPG
libSILLY_la_SOURCES += \
  loaders/SILLYJPGImageLoader.cpp \
  loaders/SILLYJPGImageContext.cpp 
libSILLY_la_CXXFLAGS += $(JPG_CFLAGS)
libSILLY_la_LIBADD += $(JPG_LIBS)
endif 

if SILLY_HAVE_PNG 
libSILLY_la_SOURCES += \
  loaders/SILLYPNGImageLoader.cpp \
  loaders/SILLYPNGImageContext.cpp 
libSILLY_la_CXXFLAGS += $(PNG_CFLAGS)
libSILLY_la_LIBADD += $(PNG_LIBS)
endif

