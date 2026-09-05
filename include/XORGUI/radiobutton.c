#include "radiobutton.h"

void drawRadioButtonFrom(Checkbox *entry, int arrayEntriesNumber, Display *dpy, Window win, GC gc, int x, int y,
                            int w, int h, char *checklistTitle, int checkboxHeight) {
    XDrawRectangle(dpy, win, gc, x, y, w, h);
    XDrawRectangle(dpy, win, gc, x, y, w, checkboxHeight / 3);
    label(dpy, gc, win, x, y, w, checkboxHeight / 3, checklistTitle,false, "center");
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        int y_padding = 30 + checkboxHeight / 2 * i;
        checkbox(entry[i].display, entry[i].gc, entry[i].win, x, y + y_padding, entry[i].w, entry[i].h / 2,
                 entry[i].label, false, entry[i].isChecked, entry[i].labelPos);
    }
}

void updateRadioButtonFrom(Checkbox *entry, MousePos mpos, int arrayEntriesNumber, Display *dpy, Window win, GC gc,
                              int x, int y, int w, int h, int checkboxHeight) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        int y_padding = 30 + checkboxHeight / 2 * i;
        if (isMouseCollidingWithRect(mpos.x, mpos.y, x, y + y_padding, entry[i].w, entry[i].h / 2)) {
            for (int i = 0; i < arrayEntriesNumber; ++i) {
                entry[i].isChecked = false;
            }
            entry[i].isChecked = true;
            XClearWindow(entry[i].display, entry[i].win);
        }
    }
}
