AC_DEFUN([SILLY_OPT], [
  dnl inline
  AC_ARG_ENABLE([inline], 
	AC_HELP_STRING([--disable-inline], [Disable function inlining]), 
	[silly_with_opt_inline=$enableval], [silly_with_opt_inline=yes])
  AC_MSG_CHECKING([whether to enable source inlining])
  if test "x$silly_with_opt_inline" = "xyes" 
  then 
     AC_DEFINE_UNQUOTED([SILLY_OPT_INLINE], [1], 
			[Set to 1 if the source code should use inline], 
			[include/SILLYOptions.h])
  fi
  AM_CONDITIONAL(SILLY_OPT_INLINE, test "x$silly_with_opt_inline" = "xyes")
  AC_MSG_RESULT($silly_with_opt_inline)
  dnl debug
  AC_ARG_ENABLE([debug], 
        AC_HELP_STRING([--enable-debug], [Activate debugging information]), 
	[silly_with_opt_debug=$enableval], [silly_with_opt_debug=no])
  AC_MSG_CHECKING([whether to enable debug mode])
  if test "x$silly_with_opt_debug" = "xyes"
  then 
     AC_DEFINE_UNQUOTED([SILLY_OPT_DEBUG], [1], 
			[Set to 1 if the source code is build in debug mode], 
			[include/SILLYOptions.h])
     CFLAGS="$CLFAGS -g3 -Wall" 
  fi
  AM_CONDITIONAL(SILLY_OPT_INLINE, test "x$silly_with_opt_debug" = "xyes")
  AC_MSG_RESULT($silly_with_opt_debug)
  dnl profile 
  AC_ARG_ENABLE([profile], 
 	AC_HELP_STRING([--enable-profile], [Build with profiling information]), 
	[silly_with_opt_profile=$enableval], [silly_with_opt_profile=no])
  AC_MSG_CHECKING([wether to enable profiling information])
  if test "x$silly_with_opt_profile" = "xyes"
  then 
     AC_DEFINE_UNQUOTED([SILLY_OPT_PROFILE], [1], 
			[Set to 1 if the source code is build with profile information], 
			[include/SILLYOptions.h])
     CFLAGS="$CFLAGS -pg"
  fi
  AM_CONDITIONAL(SILLY_OPT_PROFILE, test "x$silly_with_opt_profile" = "xyes")
  AC_MSG_RESULT($silly_with_opt_profile)
		
])

AC_DEFUN([SILLY_OPT_SUM], [
  echo "Silly options: "
  echo "  - inline: $silly_with_opt_inline"
  echo "  - debug: $silly_with_opt_debug" 
  echo "  - profile: $silly_with_opt_profile"
])

AC_DEFUN([SILLY_JPG], [
  AC_ARG_ENABLE([jpeg], 
    AC_HELP_STRING([--disable-jpeg], [Disable jpeg support]), 
    [silly_with_jpg=$enableval], [silly_with_jpg=yes])
  if test x$silly_with_jpg = xyes ; then 
    AC_CHECK_LIB([jpeg], [jpeg_read_header], [silly_with_jpg_lib=yes], [silly_with_jpg_lib=no])
    AC_CHECK_HEADER([jpeglib.h], [silly_with_jpg_header=yes], [silly_with_jpg_header=no])
    if test "x$silly_with_jpg_lib" = "xyes" -a "x$silly_with_jpg_header" = "xyes" 
    then
        AC_DEFINE_UNQUOTED([SILLY_HAVE_JPG], 
                           [1], 
                           [Defined to 1 if JPG support is enabled])
        JPG_LIBS=-ljpeg
        AC_MSG_NOTICE([Enable jpg image loading support])
        silly_with_jpg=yes
    else 
        AC_MSG_NOTICE([Disable jpg image loading support])
        silly_with_jpg=no
    fi
  else 
     AC_MSG_NOTICE([Disable jpg image loading support])
     silly_with_jpg=no
  fi 
  AM_CONDITIONAL(SILLY_HAVE_JPG, test "x$silly_with_jpg" = "xyes")
  AC_SUBST(JPG_CFLAGS)
  AC_SUBST(JPG_LIBS)
])

AC_DEFUN([SILLY_JPG_SUM], [
  echo "  - JPG: $silly_with_jpg"
])

AC_DEFUN([SILLY_PNG], [
  AC_ARG_ENABLE([png], 
    AC_HELP_STRING([--disable-png], [Disable png support]), 
    [silly_with_png=$enableval], [silly_with_png=yes])
  if test x$silly_with_png = xyes ; then 
    PKG_CHECK_MODULES([PNG], [libpng >= 1.2.10], 
        [silly_with_png=yes], 
        [silly_with_libpng=no])
    if test "x$silly_with_png" = "xyes"
    then
        AC_DEFINE_UNQUOTED([SILLY_HAVE_PNG], 
                           [1], 
                           [Defined to 1 if PNG support is enabled])
        AC_MSG_NOTICE([Enable png image format loading])
    else 
        AC_MSG_NOTICE([Disable png image format loading])
    fi
  else 
    AC_MSG_NOTICE([Disable png image format loading])
  fi
  AM_CONDITIONAL(SILLY_HAVE_PNG, test "x$silly_with_png" = "xyes")
  AC_SUBST(PNG_CFLAGS)
  AC_SUBST(PNG_LIBS)
])

AC_DEFUN([SILLY_PNG_SUM], [
  echo "  - PNG: $silly_with_png"
])

AC_DEFUN([SILLY_IMAGE_FORMAT], [
  SILLY_JPG
  SILLY_PNG
])

AC_DEFUN([SILLY_IMAGE_FORMAT_SUM], [
  echo "Image Format Supported: "
  echo "  - TGA: yes" 
  SILLY_JPG_SUM
  SILLY_PNG_SUM 
])
