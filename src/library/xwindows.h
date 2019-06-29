/*
    Copyright 2015-2018 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBTAS_XWINDOWS_H_INCL
#define LIBTAS_XWINDOWS_H_INCL

#include "global.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h> // XSetWMName

namespace libtas {

OVERRIDE Bool XQueryExtension(Display* display, const char* name, int* major_opcode_return, int* first_event_return, int* first_error_return);

OVERRIDE Window XCreateWindow(Display *display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int depth, unsigned int klass, Visual *visual, unsigned long valuemask, XSetWindowAttributes *attributes);

OVERRIDE Window XCreateSimpleWindow(Display *display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, unsigned long border, unsigned long background);

OVERRIDE int XDestroyWindow(Display *display, Window w);

OVERRIDE int XMapWindow(Display *display, Window w);
OVERRIDE int XUnmapWindow(Display *display, Window w);
OVERRIDE int XMapRaised(Display *display, Window w);

OVERRIDE int XStoreName(Display *display, Window w, const char *window_name);

OVERRIDE void XSetWMName(Display *display, Window w, XTextProperty *text_prop);

OVERRIDE int XSelectInput(Display *display, Window w, long event_mask);

OVERRIDE int XMoveWindow(Display* display, Window w, int x, int y);

OVERRIDE int XMoveResizeWindow(Display* display, Window w, int x, int y, unsigned int width, unsigned int height);

OVERRIDE int XResizeWindow(Display* display, Window w, unsigned int width, unsigned int height);

OVERRIDE int XConfigureWindow(Display* display, Window w, unsigned int value_mask, XWindowChanges* values);

OVERRIDE int XChangeProperty(Display* display, Window w, Atom property, Atom type, int format, int mode,const unsigned char* data, int nelements);

OVERRIDE int XSetWMHints(Display* display, Window w, XWMHints* wm_hints);

OVERRIDE Bool XTranslateCoordinates(Display* display, Window src_w, Window dest_w, int src_x, int src_y, int* dest_x_return, int* dest_y_return, Window* child_return);

}

#endif
