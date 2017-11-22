AC_INIT([ArtNavsegda], [1.0], [artnavsegda@gmail.com],[artnavsegda],[https://github.com/artnavsegda])
AM_INIT_AUTOMAKE
AC_MSG_NOTICE([Art Navsegda])
AC_PROG_CC
AC_CHECK_LIB([ncurses],[printw])
AC_CHECK_HEADER(modbus/modbus.h)
AC_CHECK_LIB([modbus],[modbus_free])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
