#ifndef XORGUI_PROGRESSBAR_H
#define XORGUI_PROGRESSBAR_H

#include <X11/X.h>
#include <X11/Xlib.h>

#include <string.h>
#include <stdio.h>

void drawProgressBar(Display *display, GC gc, Window win, int x, int y, int w, int h, int currentValue, int maxValue);

#endif
