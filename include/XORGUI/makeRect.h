#ifndef XORGUI_MAKERECT_H
#define XORGUI_MAKERECT_H
#include <X11/Xlib.h>

void makeRect(Display *dpy, Window win, GC gc, int x, int y, int w, int h);

#endif
