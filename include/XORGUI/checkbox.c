#include "checkbox.h"

// Make a checkbox
void checkbox(Display *display, GC gc, Window win, int x, int y, int w, int h, char *labelText, bool drawOutline,
              bool isChecked,
              char *labelPos) {
    int squareSize = 16;
    button(display, gc, win, x, y, w, h, labelText, drawOutline, "center");
    if (isChecked) {
        XFillRectangle(display, win, gc, x + w - squareSize - squareSize / 2, y + h / 2 - squareSize / 2, squareSize,
                       squareSize);
    } else {
        XDrawRectangle(display, win, gc, x + w - squareSize - squareSize / 2, y + h / 2 - squareSize / 2, squareSize,
                       squareSize);
    }
}

void drawCheckboxesFrom(Checkbox *entry, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        checkbox(entry[i].display, entry[i].gc, entry[i].win, entry[i].x, entry[i].y, entry[i].w, entry[i].h,
                 entry[i].label, entry[i].drawOutline, entry[i].isChecked, entry[i].labelPos);
    }
}

void updateCheckboxesFrom(Checkbox *entry, MousePos mpos, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        // TODO: fix hardcoded value
        if (isMouseCollidingWithRect(mpos.x, mpos.y, entry[i].x, entry[i].y, entry[i].w, entry[i].h)) {
            printf("Checkbox pressed! \n");
            fflush(stdout);
            entry[i].isChecked = !entry[i].isChecked;
            XClearWindow(entry[i].display, entry[i].win); // this fixes drawing over old text and more
        }
    }
}
