#include <XORGUI/xorgui.h>

int NUMBER_OF_BUTTONS_MAX = 17;

// Test out setting buttons with an array
Button buttonsArray[17];
Label labelArray[17];
Checkbox checkboxesArray[17];
TextField textfieldsArray[17]; // NOTE: Demo & hardcoded
KeySym ks;

// (Example) Make a function that draws everything you want and will be later used as a parameter in update_loop();
static void drawElements(Display *display, GC gc, Window win) {
    drawLabelsFrom(labelArray, NUMBER_OF_BUTTONS_MAX);
    drawButtonsFrom(buttonsArray, NUMBER_OF_BUTTONS_MAX);
    drawCheckboxesFrom(checkboxesArray, NUMBER_OF_BUTTONS_MAX);
    // NOTE: Hardcoded x and y
    drawChecklistFrom(checkboxesArray, 5, display, win, gc, 5, 5 + 320, 120, 190, "Checklist", 60);
    drawButtonsFrom(buttonsArray, NUMBER_OF_BUTTONS_MAX);
    drawTextFieldsFrom(textfieldsArray, NUMBER_OF_BUTTONS_MAX);
    drawProgressBar(display, gc, win, 130, 325, 370, 40, 888, 1337);
}

// (Example) Make a function that updates everything you want and will be later used as a parameter in update_loop();
static void updateElements(Display *display, GC gc, Window win, XEvent ev) {
    updateButtonsFrom(buttonsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, NUMBER_OF_BUTTONS_MAX);
    updateCheckboxesFrom(checkboxesArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, NUMBER_OF_BUTTONS_MAX);
    updateChecklistFrom(checkboxesArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, 5, display, win, gc, 5, 5 + 320, 120,
                        190, 60);
    updateButtonsFrom(buttonsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, NUMBER_OF_BUTTONS_MAX);
    updateTextFieldsFrom(textfieldsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, NUMBER_OF_BUTTONS_MAX, ks);
}

int main(void) {
    // Boilerplate and declarations
    Display *display = XOpenDisplay(NULL);
    if (!display) { fprintf(stderr, "Cannot open display\n"); }
    int screen = DefaultScreen(display);
    int buttonWidth = 120, buttonHeight = 40, starterX = 5, starterY = 5; // label/button/checkbox stuff
    Window win = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, 800, 600, 1,
                                     BlackPixel(display, screen), WhitePixel(display, screen));
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
        buttonsArray[i].y = starterY + 50;
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
        checkboxesArray[i].y = starterY + 100;
        checkboxesArray[i].w = buttonWidth;
        checkboxesArray[i].h = buttonHeight;
        checkboxesArray[i].label = "Radio Button";
        checkboxesArray[i].drawOutline = true;
        checkboxesArray[i].isChecked = false;
        strcpy(checkboxesArray[i].labelPos, "left"); // NOTE: Maybe a checklist should ignore this?
    }
    for (int i = 0; i < NUMBER_OF_BUTTONS_MAX; ++i) {
        textfieldsArray[i].display = display;
        textfieldsArray[i].win = win;
        textfieldsArray[i].gc = gc;
        textfieldsArray[i].x = starterX + (buttonWidth * 2 + 5) * i * 4; // Move 2nd text field off screen
        textfieldsArray[i].y = starterY + 150;
        textfieldsArray[i].w = buttonWidth * 4 + 3 * 5;
        textfieldsArray[i].h = buttonHeight * 4;
        strcpy(textfieldsArray[i].label, "Text Field");
        textfieldsArray[i].drawOutline = true;
        textfieldsArray[i].captureInput = false;
        strcpy(textfieldsArray[i].labelPos, "top-left");
    }

    // This is a loop that checks for key presses and updates
    // To draw or update elements you have to make a function that does so and insert it as a argument
    update_loop(display, gc, win, ev, drawElements, drawElements, updateElements, ks);
    return 0;
}
