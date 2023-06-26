#include "textBuffer.h"

#ifndef UI

#define UI

class UserI {

const static char EMPTY = ' ';
const static char CURSOR = '#';
public:
    int cursorX = 5;
    int cursorY = 5;

    void moveCursor(TextBuffer& buffer, int x, int y);
    void drawUI(TextBuffer& buffer);

    int getCursorX();
    int getCursorY();
};

#endif
