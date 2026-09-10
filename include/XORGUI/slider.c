#include "slider.h"

// TODO: Use progressbar() to reduce code reuse
void drawSlider(Display *display, GC gc, Window win, int x, int y, int w, int h, int currentValue, int maxValue, int sliderButtonX, bool isSelected,
                int fillWidth) {
    XDrawRectangle(display, win, gc, x, y, w, h);
    XDrawRectangle(display, win, gc, x + 2, y + 2, w - 4, h - 4);
    // Calculate percentages
    fillWidth = (currentValue * w) / maxValue;
    // Shit is likely to break without this
    if (maxValue == 0) {
        maxValue = 1;
    }
    if (currentValue == 0) {
        currentValue = 1;
        fillWidth = 4;
    }
    XFillRectangle(display, win, gc, x + 2, y + 2, fillWidth - 4, h - 4);
    XFillRectangle(display, win, gc, x + 2, y + 2, fillWidth - 4, h - 4);
    // NOTE: Hardcoded values that need to be replaced
    int sliderButtonSize = h;
    //sliderButtonX = x;
    XDrawRectangle(display, win, gc, sliderButtonX, y, sliderButtonSize / 4, sliderButtonSize);
    XDrawRectangle(display, win, gc, sliderButtonX - 2, y - 2, sliderButtonSize / 4 + 4, sliderButtonSize + 4);
    XFillRectangle(display, win, gc, sliderButtonX, y, sliderButtonSize / 4, sliderButtonSize);
    if (isSelected) {
        // XDrawRectangle(display, win, gc, sliderButtonX, y + 50, sliderButtonSize / 4, sliderButtonSize);
    }
    XFlush(display);
}

void drawSlidersFrom(const Slider *slider) {
    for (int i = 0; i < 1; ++i) {
        // NOTE: UPDATE HARDCODED VALUE
        drawSlider(slider[i].display, slider[i].gc, slider[i].win, slider[i].x, slider[i].y, slider[i].w, slider[i].h, slider[i].currentValue,
                   slider[i].maxValue, slider[i].sliderButtonX, slider[i].isSelected, slider[i].fillWidth);
    }
}

void updateSlider(Display *display, GC gc, Window win, int x, int y, int w, int h, int currentValue, int maxValue, int sliderButtonX, bool isSelected,
                  MousePos mpos, Slider *slider) {
    for (int i = 0; i < 1; ++i) {
        // TODO: fix hardcoded
        if (isMouseCollidingWithRect(mpos.x, mpos.y, slider[i].sliderButtonX, slider[i].y, h / 2, h)) {
            // printf("Slider pressed! \n"); // NOTE: Debug
            slider[i].isSelected = !slider[i].isSelected;
            fflush(stdout);
        }
        if (isMouseCollidingWithRect(mpos.x, mpos.y, slider[i].x, slider[i].y, slider[i].w, slider[i].h)) {
            int distance = mpos.x - x;
            slider[i].sliderButtonX = mpos.x;
            slider[i].currentValue = (distance * slider[i].maxValue) / slider[i].w;
            // printf("fillWidth: %d \n", slider[i].fillWidth); // NOTE: Debug
            fflush(stdout);
        }
        XClearWindow(slider[i].display, slider[i].win);
    }
}
