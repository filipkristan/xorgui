#ifndef XORGUI_UPDATE_H
#define XORGUI_UPDATE_H

#include <X11/Xlib.h>

void update_loop(Display *display, GC gc, Window win, XEvent ev,
                 void (*draw_notify)(Display *, GC, Window),
                 void (*draw_after_pressing_button1)(Display *, GC, Window),
                 void (*update_everything)(Display *, GC, Window, XEvent ev));

#endif
