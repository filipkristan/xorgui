#ifndef XORGUI_LABEL_H
#define XORGUI_LABEL_H

#include "misc.h"

typedef struct Label {
    Display *display;
    GC gc;
    Window win;
    int x;
    int y;
    int w;
    int h;
    char *label;
    bool drawOutline;
    char labelPos[16];
} Label;

void label(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline, char labelPos[16]);

void drawLabelsFrom(Label *entry, int arrayEntriesNumber);

#endif
