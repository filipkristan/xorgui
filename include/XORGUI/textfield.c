#include "textfield.h"

void TextFieldKeyUpdate(Display *display, XEvent ev, KeySym ks, TextField *entry, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        if (entry[i].captureInput == true) {
            char temp2[4096]; // TODO: Get the right size
            snprintf(temp2, sizeof(temp2), "%s", entry[i].label);
            snprintf(entry[i].label, sizeof(entry[i].label), "%s%s", temp2, XKeysymToString(ks));
        }
    }
}

void drawTextFieldsFrom(TextField *entry, int arrayEntriesNumber) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        button(entry[i].display, entry[i].gc, entry[i].win, entry[i].x, entry[i].y, entry[i].w, entry[i].h,
               entry[i].label, entry[i].drawOutline, entry[i].labelPos);
        if (entry[i].captureInput == true) {
            XDrawRectangle(entry[i].display, entry[i].win, entry[i].gc, entry[i].x + 1,
                           entry[i].y + 1, entry[i].w - 2, entry[i].h - 2);
        }
    }
}

void updateTextFieldsFrom(TextField *entry, MousePos mpos, int arrayEntriesNumber, KeySym ks) {
    for (int i = 0; i < arrayEntriesNumber; ++i) {
        // TODO: fix hardcoded value
        if (isMouseCollidingWithRect(mpos.x, mpos.y, entry[i].x, entry[i].y, entry[i].w, entry[i].h)) {
            entry[i].captureInput = true;
            if (entry[i].captureInput == true) {
                // NOTE: move here
            }
            XFillRectangle(entry[i].display, entry[i].win, entry[i].gc, entry[i].x + entry[i].w - 16 - 16 / 2,
                           entry[i].y + entry[i].h / 2 - 16 / 2, 16, 16);
            fflush(stdout);
            XClearWindow(entry[i].display, entry[i].win); // this fixes drawing over old text and more
        } else if (!isMouseCollidingWithRect(mpos.x, mpos.y, entry[i].x, entry[i].y, entry[i].w, entry[i].h)) {
            entry[i].captureInput = false;
            fflush(stdout);
            XClearWindow(entry[i].display, entry[i].win);
        }
        // drawAllArrayButtons(entry, arrayEntriesNumber); // This might fix a problem later
    }
}
