#include "button.h"

void button(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline,
                char *labelPos) {
    label(display, gc, win, x, y, w, h, labelText, drawOutline, labelPos);
    XFlush(display);
}

void drawAllArrayButtons(Button *entry, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        button(entry[i].display, entry[i].gc, entry[i].win, entry[i].x, entry[i].y, entry[i].w, entry[i].h,
                   entry[i].label, entry[i].drawOutline, entry[i].labelPos);
    }
}

void updateAllArrayButtons(Button *entry, MousePos mpos, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        // TODO: fix hardcoded value
        if (isMouseCollidingWithRect(mpos.x, mpos.y, entry[i].x, entry[i].y, entry[i].w, entry[i].h)) {
            entry[i].label = "Clicked!";
            printf("Button pressed! \n");
            XFillRectangle(entry[i].display, entry[i].win, entry[i].gc, entry[i].x + entry[i].w - 16 - 16 / 2,
                           entry[i].y + entry[i].h / 2 - 16 / 2, 16, 16);
            fflush(stdout);
            XClearWindow(entry[i].display, entry[i].win); // this fixes drawing over old text and more
        }
        // drawAllArrayButtons(entry, arrayEntriesNumber); // This might fix a problem later
    }
}
