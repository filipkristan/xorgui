#ifndef XORGUI_CHECKLIST_H
#define XORGUI_CHECKLIST_H

#include "checkbox.h"

void drawAllArrayChecklists(Checkbox *entry, int arrayEntriesNumber, Display *dpy, Window win, GC gc, int x, int y,
                            int w, int h, char *checklistTitle, int checkboxHeight);

void updateAllArrayChecklists(Checkbox *entry, MousePos mpos, int arrayEntriesNumber, Display *dpy, Window win, GC gc,
                              int x, int y, int w, int h, int checkboxHeight);

#endif
