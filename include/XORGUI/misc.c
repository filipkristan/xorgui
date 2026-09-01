#include "misc.h"

// Font is 5px wide + 1 px for space, 9px tall
int calcXlibTextWidth(char *string) {
    int res = 0;
    res = strlen(string) * 6;
    return res;
}

bool isMouseCollidingWithRect(int mouseX, int mouseY, int x, int y, int w, int h) {
    if (mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h) {
        return true;
    } else {
        return false;
    }
}
