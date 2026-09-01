#ifndef XORGUI_BUTTON_H
#define XORGUI_BUTTON_H

#include "misc.h"
#include "label.h"

typedef struct Button {
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
} Button;

// Add button to array?
void button(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline, char *labelPos);

void drawAllArrayButtons(Button *entry, int arrayEntriesNumber);

void updateAllArrayButtons(Button *entry, MousePos mpos, int arrayEntriesNumber);

#endif
