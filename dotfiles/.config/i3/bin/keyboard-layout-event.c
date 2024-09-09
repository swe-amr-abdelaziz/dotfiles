#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    XEvent e;
    Display *d;

    if (!(d = XOpenDisplay(NULL))) {
        fprintf(stderr, "Cannot open display\n");
        return 1;
    }

    int xkbEventType;
    if (!XkbQueryExtension(d, 0, &xkbEventType, 0, 0, 0)) {
        fprintf(stderr, "XKB extension not available\n");
        XCloseDisplay(d);
        return 1;
    }

    XkbSelectEvents(d, XkbUseCoreKbd, XkbStateNotifyMask, XkbStateNotifyMask);

    int lastLang = 0;
    while (1) {
        XNextEvent(d, &e);
        if (e.type == xkbEventType) {
            XkbEvent *xkbEvent = (XkbEvent *) &e;
            if (xkbEvent->any.xkb_type == XkbStateNotify) {
                int currentLang = xkbEvent->state.group;
                if (lastLang != currentLang) {
                    char command[256];
                    snprintf(command, sizeof(command), "pkill -SIGRTMIN+11 i3blocks");
                    system(command);
          		    lastLang = currentLang;
                }
            }
        }
    }

    XCloseDisplay(d);
    return 0;
}
