#include "label.h"

// Add button to array?
void label(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline,
           char *labelPos) {
    if (strcmp(labelPos, "left") == 0) {
        XDrawString(display, win, gc, x + 16 / 2, y + h / 2 + 5, labelText, strlen(labelText));
    } else if (strcmp(labelPos, "top-left") == 0) {
        XDrawString(display, win, gc, x + 6, y + 15, labelText, strlen(labelText));
    } else if (strcmp(labelPos, "bottom-left") == 0) {
    } else if (strcmp(labelPos, "right") == 0) {
    } else if (strcmp(labelPos, "top-right") == 0) {
    } else if (strcmp(labelPos, "bottom-right") == 0) {
    } else if (strcmp(labelPos, "center") == 0) {
    } else if (strcmp(labelPos, "top") == 0) {
    } else if (strcmp(labelPos, "bottom") == 0) {
    }
    if (drawOutline) {
        XDrawRectangle(display, win, gc, x, y, w, h);
    }
    XFlush(display);
}

void drawLabelsFrom(Label *entry, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        label(entry[i].display, entry[i].gc, entry[i].win, entry[i].x, entry[i].y, entry[i].w, entry[i].h,
              entry[i].label, entry[i].drawOutline, entry[i].labelPos);
    }
}
