pkgincdir=$(includedir)/SILLY

pkginc_HEADERS = \
  SILLY.h \
  SILLYOptions.h \
  SILLYBase.h \
  SILLYDataSource.h \
  SILLYMemoryDataSource.h \
  SILLYImageContext.h \
  SILLYImageLoader.h \
  SILLYImageLoaderManager.h \
  SILLYImage.h 

if SILLY_OPT_INLINE
pkginc_HEADERS += \
  SILLYDataSource.icpp \
  SILLYMemoryDataSource.icpp \
  SILLYImageContext.icpp \
  SILLYImageLoader.icpp \
  SILLYImageLoaderManager.icpp \
  SILLYImage.icpp 
endif 

noinst_HEADERS = \
  loaders/SILLYTGAImageContext.h \
  loaders/SILLYTGAImageContext.icpp \
  loaders/SILLYTGAImageLoader.h \
  loaders/SILLYTGAImageLoader.icpp \
  loaders/SILLYJPGImageContext.h \
  loaders/SILLYJPGImageContext.icpp \
  loaders/SILLYJPGImageLoader.h \
  loaders/SILLYJPGImageLoader.icpp \
  loaders/SILLYPNGImageContext.h \
  loaders/SILLYPNGImageContext.icpp \
  loaders/SILLYPNGImageLoader.h \
  loaders/SILLYPNGImageLoader.icpp 

