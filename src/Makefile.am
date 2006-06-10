INCLUDES=-I$(top_srcdir)/include 

lib_LTLIBRARIES = libsilly.la
libsilly_la_CXXFLAGS= 
libsilly_la_LIBADD=
libsilly_la_SOURCES= \
  SILLYImageHeader.cpp \
  SILLYDataSource.cpp \
  SILLYMemoryDataSource.cpp \
  SILLYImageLoader.cpp \
  SILLYTGAImageLoader.cpp \
  SILLYImageLoaderManager.cpp \
  SILLYImage.cpp \
  loaders/SILLYTGAImageLoader.cpp \
  loaders/SILLYTGAImageContext.cpp 



if SILLY_HAVE_JPG
libsilly_la_SOURCES += \
  loaders/SILLYJPGImageLoader.cpp \
  loaders/SILLYJPGImageContext.cpp 
libsilly_la_CXXFLAGS += $(JPG_CFLAGS)
libsilly_la_LIBADD += $(JPG_LIBS)
endif 

if SILLY_HAVE_PNG 
libsilly_la_SOURCES += \
  loaders/SILLYPNGImageLoader.cpp \
  loaders/SILLYPNGImageContext.cpp 
libsilly_la_CXXFLAGS += $(PNG_CFLAGS)
libsilly_la_LIBADD += $(PNG_LIBS)
endif

