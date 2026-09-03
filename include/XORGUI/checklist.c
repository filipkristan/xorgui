#include "checklist.h"

void drawChecklistFrom(Checkbox *entry, int arrayEntriesNumber, Display *dpy, Window win, GC gc, int x, int y,
                            int w, int h, char *checklistTitle, int checkboxHeight) {
    XDrawRectangle(dpy, win, gc, x, y, w, h);
    XDrawRectangle(dpy, win, gc, x, y, w, checkboxHeight / 3);
    label(dpy, gc, win, x, y, w, checkboxHeight / 3, checklistTitle,false, "center");
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        int y_padding = 30 + checkboxHeight / 2 * i;

        // TODO: IMPROVE DEBUG
        // XDrawRectangle(entry[i].display,  entry[i].win, entry[i].gc, x, y + y_padding, entry[i].w, entry[i].h);

        checkbox(entry[i].display, entry[i].gc, entry[i].win, x, y + y_padding, entry[i].w, entry[i].h / 2,
                 entry[i].label, false, entry[i].isChecked, entry[i].labelPos);
    }
}

void updateChecklistFrom(Checkbox *entry, MousePos mpos, int arrayEntriesNumber, Display *dpy, Window win, GC gc,
                              int x, int y, int w, int h, int checkboxHeight) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        int y_padding = 30 + checkboxHeight / 2 * i;

        // TODO: IMPROVE DEBUG
        // printf("%d %d \n",mpos.x,mpos.y);
        // fflush(stdout);

        if (isMouseCollidingWithRect(mpos.x, mpos.y, x, y + y_padding, entry[i].w, entry[i].h / 2)) {
            printf("Checkbox pressed! \n");
            fflush(stdout);
            entry[i].isChecked = !entry[i].isChecked;
            XClearWindow(entry[i].display, entry[i].win);
        }
    }
}
