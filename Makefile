#############################################################################
# Makefile for building: AdAndCrapBlock
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sun Nov 10 11:59:52 2013
# Project:  AdAndCrapBlock.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile AdAndCrapBlock.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		downloader.cpp \
		parserthread.cpp \
		processsimthread.cpp \
		pathhelper.cpp \
		addurl.cpp moc_mainwindow.cpp \
		moc_downloader.cpp \
		moc_parserthread.cpp \
		moc_processsimthread.cpp \
		moc_pathhelper.cpp \
		moc_addurl.cpp \
		qrc_AppResources.cpp
OBJECTS       = main.o \
		mainwindow.o \
		downloader.o \
		parserthread.o \
		processsimthread.o \
		pathhelper.o \
		addurl.o \
		moc_mainwindow.o \
		moc_downloader.o \
		moc_parserthread.o \
		moc_processsimthread.o \
		moc_pathhelper.o \
		moc_addurl.o \
		qrc_AppResources.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		AdAndCrapBlock.pro
QMAKE_TARGET  = AdAndCrapBlock
DESTDIR       = 
TARGET        = AdAndCrapBlock

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_addurl.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: AdAndCrapBlock.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile AdAndCrapBlock.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile AdAndCrapBlock.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/AdAndCrapBlock1.0.0 || $(MKDIR) .tmp/AdAndCrapBlock1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/AdAndCrapBlock1.0.0/ && $(COPY_FILE) --parents mainwindow.h downloader.h parserthread.h processsimthread.h pathhelper.h addurl.h .tmp/AdAndCrapBlock1.0.0/ && $(COPY_FILE) --parents AppResources.qrc .tmp/AdAndCrapBlock1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp downloader.cpp parserthread.cpp processsimthread.cpp pathhelper.cpp addurl.cpp .tmp/AdAndCrapBlock1.0.0/ && $(COPY_FILE) --parents mainwindow.ui addurl.ui .tmp/AdAndCrapBlock1.0.0/ && (cd `dirname .tmp/AdAndCrapBlock1.0.0` && $(TAR) AdAndCrapBlock1.0.0.tar AdAndCrapBlock1.0.0 && $(COMPRESS) AdAndCrapBlock1.0.0.tar) && $(MOVE) `dirname .tmp/AdAndCrapBlock1.0.0`/AdAndCrapBlock1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/AdAndCrapBlock1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_downloader.cpp moc_parserthread.cpp moc_processsimthread.cpp moc_pathhelper.cpp moc_addurl.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_downloader.cpp moc_parserthread.cpp moc_processsimthread.cpp moc_pathhelper.cpp moc_addurl.cpp
moc_mainwindow.cpp: downloader.h \
		ui_mainwindow.h \
		parserthread.h \
		pathhelper.h \
		processsimthread.h \
		addurl.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_downloader.cpp: downloader.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) downloader.h -o moc_downloader.cpp

moc_parserthread.cpp: parserthread.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) parserthread.h -o moc_parserthread.cpp

moc_processsimthread.cpp: processsimthread.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) processsimthread.h -o moc_processsimthread.cpp

moc_pathhelper.cpp: pathhelper.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) pathhelper.h -o moc_pathhelper.cpp

moc_addurl.cpp: addurl.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) addurl.h -o moc_addurl.cpp

compiler_rcc_make_all: qrc_AppResources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_AppResources.cpp
qrc_AppResources.cpp: AppResources.qrc \
		icons/aacblock_middle.png \
		icons/aacblock_small.png \
		icons/aacblock_big.png
	/usr/bin/rcc -name AppResources AppResources.qrc -o qrc_AppResources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_addurl.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_addurl.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_addurl.h: addurl.ui
	/usr/bin/uic-qt4 addurl.ui -o ui_addurl.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		downloader.h \
		ui_mainwindow.h \
		parserthread.h \
		pathhelper.h \
		processsimthread.h \
		addurl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		downloader.h \
		ui_mainwindow.h \
		parserthread.h \
		pathhelper.h \
		processsimthread.h \
		addurl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

downloader.o: downloader.cpp downloader.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o downloader.o downloader.cpp

parserthread.o: parserthread.cpp parserthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o parserthread.o parserthread.cpp

processsimthread.o: processsimthread.cpp processsimthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o processsimthread.o processsimthread.cpp

pathhelper.o: pathhelper.cpp pathhelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pathhelper.o pathhelper.cpp

addurl.o: addurl.cpp addurl.h \
		ui_addurl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addurl.o addurl.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_downloader.o: moc_downloader.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_downloader.o moc_downloader.cpp

moc_parserthread.o: moc_parserthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_parserthread.o moc_parserthread.cpp

moc_processsimthread.o: moc_processsimthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_processsimthread.o moc_processsimthread.cpp

moc_pathhelper.o: moc_pathhelper.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pathhelper.o moc_pathhelper.cpp

moc_addurl.o: moc_addurl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_addurl.o moc_addurl.cpp

qrc_AppResources.o: qrc_AppResources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_AppResources.o qrc_AppResources.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/bin/ || $(MKDIR) $(INSTALL_ROOT)/usr/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/usr/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/bin/ 


install_data: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/ || $(MKDIR) $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/ 
	-$(INSTALL_FILE) /home/memoryleakx/Projects/AdAndCrapBlock/icons/aacblock_big.png $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/
	-$(INSTALL_FILE) /home/memoryleakx/Projects/AdAndCrapBlock/icons/aacblock_middle.png $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/
	-$(INSTALL_FILE) /home/memoryleakx/Projects/AdAndCrapBlock/icons/aacblock_small.png $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/


uninstall_data:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/aacblock_big.png 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/aacblock_middle.png 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/aacblock_small.png
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/share/AdAndCrapBlock/icons/ 


install_desktop: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/share/applications/ || $(MKDIR) $(INSTALL_ROOT)/usr/share/applications/ 
	-$(INSTALL_FILE) /home/memoryleakx/Projects/AdAndCrapBlock/AdAndCrapBlock.desktop $(INSTALL_ROOT)/usr/share/applications/


uninstall_desktop:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/usr/share/applications/AdAndCrapBlock.desktop
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/share/applications/ 


install:  install_target install_data install_desktop  FORCE

uninstall: uninstall_target uninstall_data uninstall_desktop   FORCE

FORCE:

