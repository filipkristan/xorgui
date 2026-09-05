#ifndef XORGUI_RADIOBUTTON_H
#define XORGUI_RADIOBUTTON_H
#include "checkbox.h"

void drawRadioButtonFrom(Checkbox *entry, int arrayEntriesNumber, Display *dpy, Window win, GC gc, int x, int y,
                         int w, int h, char *checklistTitle, int checkboxHeight);

void updateRadioButtonFrom(Checkbox *entry, MousePos mpos, int arrayEntriesNumber, Display *dpy, Window win, GC gc,
                           int x, int y, int w, int h, int checkboxHeight);

#endif
