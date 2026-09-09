#ifndef XORGUI_SLIDER_H
#define XORGUI_SLIDER_H

#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "misc.h"

typedef struct Slider {
    Display *display;
    GC gc;
    Window win;
    int x;
    int y;
    int w;
    int h;
    int currentValue;
    int maxValue;
    int sliderButtonX;
    int fillWidth;
    bool isSelected;
} Slider;

void drawSlider(Display *display, GC gc, Window win, int x, int y, int w, int h, int currentValue, int maxValue, int sliderButtonX, bool isSelected,
                int fillWidth);

void drawSlidersFrom(const Slider *slider);

void updateSlider(Display *display, GC gc, Window win, int x, int y, int w, int h, int currentValue, int maxValue, int sliderButtonX, bool isSelected,
                  MousePos mpos, Slider *slider);

#endif
