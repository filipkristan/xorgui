#include <XORGUI/xorgui.h>

KeySym ks;

// Test out setting buttons with an array
// // NOTE: Demo & hardcoded
int NUMBER_OF_BUTTONS_MAX = 6;
Button buttonsArray[6];
Label labelArray[6];
Checkbox checkboxesArray[6];
extern TextField textfieldsArray[2]; // TODO: Unfuck this
Slider sliderArray[2];

// (Example) Make a function that draws everything you want and will be later used as a parameter in update_loop();
static void drawElements(Display *display, GC gc, Window win) {
    drawLabelsFrom(labelArray, sizeof(labelArray) / sizeof(labelArray[0]));
    drawButtonsFrom(buttonsArray, sizeof(buttonsArray) / sizeof(buttonsArray[0]));
    drawCheckboxesFrom(checkboxesArray, sizeof(checkboxesArray) / sizeof(checkboxesArray[0]));
    // NOTE: Hardcoded x and y
    drawChecklistFrom(checkboxesArray, 5, display, win, gc, 5, 5 + 300, 120, 190, "Checklist", 60);
    drawTextFieldsFrom(textfieldsArray, 2); // TODO: fix hardcoded value
    drawProgressBar(display, gc, win, 130, 305, 370, 40, 888, 1337);
    drawSlidersFrom(sliderArray);
}

// (Example) Make a function that updates everything you want and will be later used as a parameter in update_loop();
static void updateElements(Display *display, GC gc, Window win, XEvent ev) {
    updateButtonsFrom(buttonsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, sizeof(buttonsArray) / sizeof(buttonsArray[0]));
    updateCheckboxesFrom(checkboxesArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, sizeof(checkboxesArray) / sizeof(checkboxesArray[0]));
    updateChecklistFrom(checkboxesArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, 5, display, win, gc, 5, 5 + 300, 120, 190, 60);
    updateButtonsFrom(buttonsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, sizeof(buttonsArray) / sizeof(buttonsArray[0]));
    updateTextFieldsFrom(textfieldsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, 2, ks); // TODO: fix hardcoded value
    updateSlider(display, gc, win, 130, 350, 370, 40, 0, 1337, 130, false, (MousePos){ev.xbutton.x, ev.xbutton.y}, sliderArray);
}

// (Example) Make a function that updates keys you want and will be later used as a parameter in update_loop();
static void updateKeys(Display *display, XEvent ev, KeySym ks, TextField *entry, int arrayEntriesNumber) {
    // TODO: Remove unused "int arrayEntriesNumber"
    TextFieldKeyUpdate(display, ev, ks, textfieldsArray, arrayEntriesNumber);
}

int main(void) {
    // Boilerplate and declarations
    Display *display = XOpenDisplay(NULL);
    if (!display) { fprintf(stderr, "Cannot open display\n"); }
    int screen = DefaultScreen(display);
    int buttonWidth = 120, buttonHeight = 40, starterX = 5, starterY = 5; // label/button/checkbox stuff
    Window win = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, 800, 600, 1, BlackPixel(display, screen), WhitePixel(display, screen));
    XMapWindow(display, win); // Maps the window
    XStoreName(display, win, "Xorgui");
    XSelectInput(display, win, ButtonPressMask | ButtonReleaseMask | ExposureMask | KeyPressMask | KeyReleaseMask);
    XWindowAttributes xwa;
    XGetWindowAttributes(display, win, &xwa);
    GC gc = DefaultGC(display, screen);
    XFlush(display);
    XEvent ev;
    //KeySym ks = 0;
    // Set widgets for demonstration
    for (int i = 0; i < NUMBER_OF_BUTTONS_MAX; ++i) {
        labelArray[i].display = display;
        labelArray[i].win = win;
        labelArray[i].gc = gc;
        labelArray[i].x = starterX + (buttonWidth + 5) * i;
        labelArray[i].y = starterY;
        labelArray[i].w = buttonWidth;
        labelArray[i].h = buttonHeight;
        labelArray[i].label = "Label";
        labelArray[i].drawOutline = true;
        strcpy(labelArray[i].labelPos, "left");
    }
    for (int i = 0; i < NUMBER_OF_BUTTONS_MAX; ++i) {
        buttonsArray[i].display = display;
        buttonsArray[i].win = win;
        buttonsArray[i].gc = gc;
        buttonsArray[i].x = starterX + (buttonWidth + 5) * i;
        buttonsArray[i].y = starterY + 45;
        buttonsArray[i].w = buttonWidth;
        buttonsArray[i].h = buttonHeight;
        buttonsArray[i].label = "Button";
        buttonsArray[i].drawOutline = true;
        strcpy(buttonsArray[i].labelPos, "center");
    }
    for (int i = 0; i < NUMBER_OF_BUTTONS_MAX; ++i) {
        checkboxesArray[i].display = display;
        checkboxesArray[i].win = win;
        checkboxesArray[i].gc = gc;
        checkboxesArray[i].x = starterX + (buttonWidth + 5) * i;
        checkboxesArray[i].y = starterY + 90;
        checkboxesArray[i].w = buttonWidth;
        checkboxesArray[i].h = buttonHeight;
        checkboxesArray[i].label = "Radio Button";
        checkboxesArray[i].drawOutline = true;
        checkboxesArray[i].isChecked = false;
        strcpy(checkboxesArray[i].labelPos, "left"); // NOTE: Maybe a checklist should ignore this?
    }
    for (int i = 0; i < 2; ++i) {
        // TODO: fix hardcoded value
        textfieldsArray[i].display = display;
        textfieldsArray[i].win = win;
        textfieldsArray[i].gc = gc;
        textfieldsArray[i].x = starterX + (buttonWidth + 5) * i * 3;
        textfieldsArray[i].y = starterY + 135;
        textfieldsArray[i].w = buttonWidth * 3 + 2 * 5;
        textfieldsArray[i].h = buttonHeight * 4;
        strcpy(textfieldsArray[i].label, "Text Field");
        textfieldsArray[i].drawOutline = true;
        textfieldsArray[i].captureInput = false;
        strcpy(textfieldsArray[i].labelPos, "top-left");
    }
    for (int i = 0; i < 1; ++i) {
        // TODO: fix hardcoded value
        sliderArray[i].display = display;
        sliderArray[i].win = win;
        sliderArray[i].gc = gc;
        sliderArray[i].x = 130;
        sliderArray[i].y = 350;
        sliderArray[i].w = 370;
        sliderArray[i].h = 40;
        sliderArray[i].isSelected = false;
        sliderArray[i].currentValue = 410;
        sliderArray[i].maxValue = 1337;
        sliderArray[i].sliderButtonX = sliderArray[i].x; // Not ideal but will stay like this for now
    }

    // This is a loop that checks for key presses and updates
    // To draw or update elements you have to make a function that does so and insert it as a argument
    update_loop(display, gc, win, ev, drawElements, drawElements, updateElements, updateKeys, ks);
    return 0;
}
