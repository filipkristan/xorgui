#ifndef XORGUI_LABEL_H
#define XORGUI_LABEL_H

#include "makeRect.h"
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
    char *labelPos;
} Label;

void label(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline, char *labelPos);

void drawAllArrayLabels(Label *entry, int arrayEntriesNumber);

#endif
