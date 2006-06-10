AC_DEFUN([SILLY_OPT], [
  silly_with_opt_inline=no
  silly_with_opt_debug=no
  silly_with_opt_profile=no

  dnl inline
  AC_ARG_ENABLE([inline], 
	AC_HELP_STRING([--disable-inline], [Disable function inlining]), 
	[silly_with_opt_inline=$enableval], [silly_with_opt_inline=no])
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
     CFLAGS="$CLFAGS -g3 -Wall -W" 
  fi
  AM_CONDITIONAL(SILLY_OPT_INLINE, test "x$silly_with_opt_debug" = "xyes")
  AC_MSG_RESULT($silly_with_opt_debug)
  dnl profile 
  AC_ARG_ENABLE([profile], 
 	AC_HELP_STRING([--enable-profile], [Build with profiling information]), 
	[silly_with_opt_profile=$enableval], [silly_with_opt_inline=no])
  AC_MSG_CHECKING([wether to enable profiling information])
  if test "x$silly_with_opt_profile" = "xyes"
  then 
     AC_DEFINE_UNQUOTED([SILLY_OPT_PROFILE], [1], 
			[Set to 1 if the source code is build with profile information], 
			[include/SILLYOptions.h])
     CFLAGS="$CFLAGS -pg"
  fi
  AM_CONDITIONAL(SILLY_OPT_PROFILE, test "x$silly_with_opt_profile" = "xyes")
  AC_MSG_RESULT($silly_with_opt_profile
		
])

AC_DEFUN([SILLY_OPT_SUM], [
  echo "Silly options: "
  echo "  - inline: $silly_with_opt_inline"
  echo "  - debug: $silly_with_opt_debug" 
  echo "  - profile: $silly_with_opt_profile"
])

AC_DEFUN([SILLY_JPG], [
  silly_with_jpg=no
  
])

AC_DEFUN([SILLY_JPG_SUM], [
  echo "  - JPG: $silly_with_jpg"
])

AC_DEFUN([SILLY_PNG], [
  silly_with_png=no

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