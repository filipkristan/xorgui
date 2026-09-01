#ifndef XORGUI_MISC_H
#define XORGUI_MISC_H

#include <X11/Xlib.h>
#include <X11/Xlib.h>
#include <X11/Xos.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} MousePos;

int calcXlibTextWidth(char *string);

bool isMouseCollidingWithRect(int mouseX, int mouseY, int x, int y, int w, int h);

#endif
