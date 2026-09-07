#ifndef XORGUI_TEXTFIELD_H
#define XORGUI_TEXTFIELD_H

#include "misc.h"
#include "button.h"

typedef struct TextField {
    Display *display;
    GC gc;
    Window win;
    int x;
    int y;
    int w;
    int h;
    char label[4096];
    bool drawOutline;
    char labelPos[16];
    bool captureInput;
} TextField;

void drawTextFieldsFrom(TextField *entry, int arrayEntriesNumber);

void updateTextFieldsFrom(TextField *entry, MousePos mpos, int arrayEntriesNumber, KeySym ks);

void TextFieldKeyUpdate(Display *display, XEvent ev, KeySym ks, TextField *entry, int arrayEntriesNumber);

#endif
