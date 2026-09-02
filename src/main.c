#include <XORGUI/xorgui.h>

int NUMBER_OF_BUTTONS_MAX = 17;

// Test out setting buttons with an array
Button buttonsArray[17];
Label labelArray[17];
Checkbox checkboxesArray[17];

// (Example) Make a function that draws everything you want and will be later used as a parameter in update_loop();
void drawElements(Display *display, GC gc, Window win) {
    //drawAllArrayLabels(labelArray, NUMBER_OF_BUTTONS_MAX);
    //drawAllArrayButtons(buttonsArray, NUMBER_OF_BUTTONS_MAX);
    // drawAllArrayCheckboxes(checkboxesArray, NUMBER_OF_BUTTONS_MAX);
    drawAllArrayChecklists(checkboxesArray, 5, display, win, gc, 5, 5, 120, 190, "Checklist", 60);
}

// (Example) Make a function that updates everything you want and will be later used as a parameter in update_loop();
void updateElements(Display *display, GC gc, Window win, XEvent ev) {
    //updateAllArrayButtons(buttonsArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, NUMBER_OF_BUTTONS_MAX);
    //updateAllArrayCheckboxes(checkboxesArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, NUMBER_OF_BUTTONS_MAX);
    updateAllArrayChecklists(checkboxesArray, (MousePos){ev.xbutton.x, ev.xbutton.y}, 5, display, win, gc, 5, 5, 120,
                             190, 60);
}

int main(void) {
    // Boilerplate and declarations
    Display *display = XOpenDisplay(NULL);
    if (!display) { fprintf(stderr, "Cannot open display\n"); }
    int screen = DefaultScreen(display);
    int buttonWidth = 120, buttonHeight = 40, starterX = 5, starterY = 5; // label/button/checkbox stuff
    MousePos mouse = {0, 0};
    Window win = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, 1280, 720, 1,
                                     BlackPixel(display, screen), WhitePixel(display, screen));
    XMapWindow(display, win); // Maps the window
    XStoreName(display, win, "Xorgui");
    XSelectInput(display, win, ButtonPressMask | ButtonReleaseMask | ExposureMask);
    XWindowAttributes xwa;
    XGetWindowAttributes(display, win, &xwa);
    GC gc = DefaultGC(display, screen);

    XFlush(display);
    XEvent ev;

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
        labelArray[i].labelPos = "left";
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
        buttonsArray[i].labelPos = "center";
    }
    for (int i = 0; i < NUMBER_OF_BUTTONS_MAX; ++i) {
        checkboxesArray[i].display = display;
        checkboxesArray[i].win = win;
        checkboxesArray[i].gc = gc;
        checkboxesArray[i].x = starterX + (buttonWidth + 5) * i;
        checkboxesArray[i].y = starterY + 100;
        checkboxesArray[i].w = buttonWidth;
        checkboxesArray[i].h = buttonHeight;
        checkboxesArray[i].label = "Checkbox";
        checkboxesArray[i].drawOutline = true;
        checkboxesArray[i].isChecked = false;
        checkboxesArray[i].labelPos = "right";
    }

    // This is a loop that checks for key presses and updates
    // To draw or update elements you have to make a function that does so and insert it as a argument
    update_loop(display, gc, win, ev, drawElements, drawElements, updateElements);
    return 0;
}
