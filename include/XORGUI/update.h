#ifndef XORGUI_UPDATE_H
#define XORGUI_UPDATE_H

#include <X11/Xlib.h>
#include <stdio.h>

#include "textfield.h"

extern TextField textfieldsArray[17];

void update_loop(Display *display, GC gc, Window win, XEvent ev,
                 void (*draw_notify)(Display *, GC, Window),
                 void (*draw_after_pressing_button1)(Display *, GC, Window),
                 void (*update_everything)(Display *, GC, Window, XEvent ev), KeySym ks);

#endif
