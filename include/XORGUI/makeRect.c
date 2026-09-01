#include "makeRect.h"

void makeRect(Display *dpy, Window win, GC gc, int x, int y, int w, int h) {
    XFillRectangle(dpy, win, gc, x, y, w, h);
    XFlush(dpy);
}
