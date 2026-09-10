#include "update.h"

TextField textfieldsArray[2];

void update_loop(Display *display, GC gc, Window win, XEvent ev,
                 void (*draw_notify)(Display *, GC, Window),
                 void (*draw_after_pressing_button1)(Display *, GC, Window),
                 void (*update_everything)(Display *, GC, Window, XEvent ev),
                 void (*update_keys)(Display *, XEvent, KeySym, TextField *, int),
                 KeySym ks) {
    XFlush(display);
    for (;;) {
        XNextEvent(display, &ev);
        switch (ev.type) {
            case KeyPress:
                // Sure, XKeycodeToKeysym might be deprecated but i'm too lazy to do anything about it.
                ks = XKeycodeToKeysym(display, ev.xkey.keycode, 0);
                update_keys(display, ev, ks, textfieldsArray, 2); // TODO: Fix hardcoded value
            case Expose:
                // Displays after showing the window
                XClearWindow(display, win);
                draw_notify(display, gc, win);
                break;
            case ClientMessage:
                XCloseDisplay(display);
                break;
            case MotionNotify:
                break;
            case ButtonPress:
                switch (ev.xbutton.button) {
                    case Button1: // Left click
                        // update after necessary calculations were done
                        update_everything(display, gc, win, ev);
                        draw_after_pressing_button1(display, gc, win);
                        XSync(display, True);
                        break;
                    default:
                        break;
                }
                break;
            default: ;
        }
    }
}
