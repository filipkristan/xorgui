#ifndef XORGUI_CHECKBOX_H
#define XORGUI_CHECKBOX_H

#include "button.h"
#include "misc.h"

typedef struct Checkbox {
    Display *display;
    GC gc;
    Window win;
    int x;
    int y;
    int w;
    int h;
    char *label;
    bool drawOutline;
    bool isChecked;
    char *labelPos;
} Checkbox;

void checkbox(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline,
              bool isChecked, char *labelPos);

void drawCheckboxesFrom(Checkbox *entry, int arrayEntriesNumber);

void updateCheckboxesFrom(Checkbox *entry, MousePos mpos, int arrayEntriesNumber);

#endif
