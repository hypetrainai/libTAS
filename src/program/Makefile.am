bin_PROGRAMS = libTAS

libTAS_QTSOURCES = GameLoop.h ui/AnnotationsWindow.h ui/AutoSaveWindow.h ui/ControllerAxisWidget.h ui/ControllerTabWindow.h ui/ControllerWidget.h ui/EncodeWindow.h ui/ExecutableWindow.h ui/GameInfoWindow.h ui/InputEditorModel.h ui/InputEditorView.h ui/InputEditorWindow.h ui/InputWindow.h ui/KeyPressedDialog.h ui/MainWindow.h ui/OsdWindow.h ui/PointerScanModel.h ui/PointerScanWindow.h ui/RamSearchModel.h ui/RamSearchWindow.h ui/RamWatchEditWindow.h ui/RamWatchModel.h ui/RamWatchWindow.h

libTAS_MOCSOURCES = $(libTAS_QTSOURCES:.h=_moc.cpp)

libTAS_SOURCES = AutoSave.cpp Config.cpp GameLoop.cpp KeyMapping.cpp main.cpp MovieFile.cpp utils.cpp ui/AnnotationsWindow.cpp ui/AutoSaveWindow.cpp ui/ControllerAxisWidget.cpp ui/ControllerTabWindow.cpp ui/ControllerWidget.cpp ui/EncodeWindow.cpp ui/ErrorChecking.cpp ui/ExecutableWindow.cpp ui/GameInfoWindow.cpp ui/InputEditorModel.cpp ui/InputEditorView.cpp ui/InputEditorWindow.cpp ui/InputWindow.cpp ui/KeyPressedDialog.cpp ui/MainWindow.cpp ui/OsdWindow.cpp ui/PointerScanModel.cpp ui/PointerScanWindow.cpp ui/RamSearchModel.cpp ui/RamSearchWindow.cpp ui/RamWatchEditWindow.cpp ui/RamWatchModel.cpp ui/RamWatchWindow.cpp ramsearch/IRamWatch.cpp ramsearch/IRamWatchDetailed.cpp ramsearch/MemSection.cpp ../shared/AllInputs.cpp ../shared/SingleInput.cpp ../shared/messages.cpp ../shared/sockethelpers.cpp $(libTAS_MOCSOURCES)

libTAS_CXXFLAGS = $(QT5_CFLAGS) -std=c++11 -Wall -fno-stack-protector -Wno-float-equal -fPIC
libTAS_LDADD = $(QT5_LIBS)

.h_moc.cpp:
	@MOC@ -o $@ $(CPPFLAGS) $<

SUFFIXES = .h _moc.cpp

BUILT_SOURCES = pylibtas_swig.cpp

AM_CXXFLAGS = -I$(shell $(PYTHON) -c 'import numpy; print(numpy.get_include())')
pkgpython_PYTHON = pylibtas.py
pkgpyexec_LTLIBRARIES = _pylibtas.la
_pylibtas_la_SOURCES = pylibtas_swig.cpp $(libTAS_SOURCES)
_pylibtas_la_CPPFLAGS = $(AX_SWIG_PYTHON_CPPFLAGS) $(libTAS_CXXFLAGS)
_pylibtas_la_LDFLAGS = -module
_pylibtas_la_LIBADD = $(libTAS_LDADD)

pylibtas_swig.cpp : pylibtas.i 
	$(SWIG) $(AX_SWIG_PYTHON_OPT) -o $@ $<

CLEANFILES = $(libTAS_MOCSOURCES) pylibtas_swig.cpp _pylibtas.so pylibtas.py *.pyc
