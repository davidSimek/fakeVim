#include "imageBuffer.h"

#ifndef UI

#define UI

class UserI {

const static char EMPTY = ' ';
const static char CURSOR = '#';
public:
    int cursorX = 5;
    int cursorY = 5;

    void moveCursor(ImageBuffer& ib, int x, int y);
    void drawUI(ImageBuffer& buffer);

    int getCursorX();
    int getCursorY();

private:
    int textX1;
    int textY1;
    int textX2;
    int textY2;
};

#endif
