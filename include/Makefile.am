pkgincdir=$(includedir)/SILLY

pkginc_HEADERS = \
  SILLY.h \
  SILLYOptions.h \
  SILLYBase.h \
  SILLYDataSource.h \
  SILLYMemoryDataSource.h \
  SILLYImageHeader.h \
  SILLYImageContext.h \
  SILLYImageLoader.h \
  SILLYImageLoaderManager.h \
  SILLYImage.h 

if SILLY_OPT_INLINE
pkginc_HEADERS += \
  SILLYDataSource.iccp \
  SILLYMemoryDataSource.icpp \
  SILLYImageHeader.icpp \
  SILLYImageContext.icpp \
  SILLYImageLoader.icpp \
  SILLYImageLoaderManager.icpp \
  SILLYImage.icpp 
endif 

noinst_HEADERS = \
  loaders/SILLYTGAImageContext.h \
  loaders/SILLYTGAImageLoader.h \
  loaders/SILLYJPGImageContext.h \
  loaders/SILLYJPGImageLoader.h \
  loaders/SILLYPNGImageContext.h \
  loaders/SILLYPNGImageLoader.h 

