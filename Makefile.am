ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS = -I$(top_srcdir)/include -L/usr/local/lib -I/usr/include/eigen3 -L/opt/ros/groovy/lib
AM_CFLAGS = -std=gnu99 -L/usr/local/lib
AM_LDFLAGS = -L/opt/ros/groovy/lib

EXTRA_DIST = tables/control.table

motionlibs = -lm -lrt -lach libhuboctrl.la libdaemonizer.la -lhuboparams
roslibs = -lconsole_bridge -lurdfdom_model

init_ddir = /etc/init.d
init_d_SCRIPTS = scripts/hubo-motion

# installed under $prefix/include/
include_HEADERS = include/Hubo_Control.h include/control-daemon.h include/daemonizer.h include/manip.h include/motion-trajectory.h include/balance-daemon.h include/hubo-zmp.h include/DrcHuboKin.h

bin_PROGRAMS = control-daemon manip-daemon balance-daemon trajectory-run

hubo_ctrldir = /usr/lib
hubo_ctrl_LTLIBRARIES = libhuboctrl.la libdaemonizer.la libdrchubokin.la #libhubowalker.la 
#libhubowalker_la_SOURCES = src/Walker.cpp
#libhubowalker_la_LDFLAGS = -module -avoid-version -shared
#libhubowalker_la_LDADD = -lm -lrt -lach libhuboctrl.la libdaemonizer.la -lhuboparams
libdaemonizer_la_SOURCES = src/daemonizer.c
libdaemonizer_la_LDFLAGS = -module -avoid-version -shared
libhuboctrl_la_SOURCES = src/Hubo_Control.cpp
libhuboctrl_la_LDFLAGS = -module -avoid-version -shared
libdrchubokin_la_SOURCES = src/DrcHuboKin.cpp
libdrchubokin_la_LDFLAGS = -module -avoid-version -shared
#libhuboctrl_la_LIBADD = -lm -lach

huboctrlconfdir=/etc/hubo-ach
huboctrlconf_DATA = tables/control.table

control_daemon_SOURCES = src/control-daemon.c
control_daemon_LDADD = -lm -lrt -lach -lc libdaemonizer.la -lhuboparams

manip_daemon_SOURCES = src/manip-daemon.cpp
manip_daemon_LDADD = $(motionlibs)

trajectory_run_SOURCES = src/trajectory-run.cpp
trajectory_run_LDADD = $(motionlibs)

balance_daemon_SOURCES = src/balance-daemon.cpp src/Walker.cpp
balance_daemon_LDADD = $(motionlibs) $(roslibs) -lRobotKin libdrchubokin.la
