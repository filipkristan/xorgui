#include "progressbar.h"

void drawProgressBar(Display *display, GC gc, Window win, int x, int y, int w, int h, int currentValue, int maxValue) {
    XDrawRectangle(display, win, gc, x, y, w, h);
    XDrawRectangle(display, win, gc, x + 2, y + 2, w - 4, h - 4);
    // Calculate percentages
    int fillWidth = (currentValue * w) / maxValue;
    // Shit is likely to break without this
    if (maxValue == 0) {
        maxValue = 1;
    }
    if (currentValue == 0) {
        currentValue = 1;
        fillWidth = 4;
    }
    XFillRectangle(display, win, gc, x + 2, y + 2, fillWidth - 4, h - 4);
}
