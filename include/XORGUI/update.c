#include "update.h"

void update_loop(Display *display, GC gc, Window win, XEvent ev, void (*draw_notify)(Display *, GC, Window),
                 void (*draw_after_pressing_button1)(Display *, GC, Window),
                 void (*update_everything)(Display *, GC, Window, XEvent ev)) {
    XFlush(display);
    for (;;) {
        XNextEvent(display, &ev);
        switch (ev.type) {
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
                    draw_after_pressing_button1(display, gc, win); // draw after left clicking
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