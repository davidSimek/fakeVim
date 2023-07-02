#include "imageBuffer.h"
#include "textBuffer.h"

#ifndef UI

#define UI

class UserI {

const static char EMPTY = ' ';
const static char CURSOR = '#';
public:

    UserI(TextBuffer& tb) {
        this->tb = tb;
    }

    int cursorX = 5;
    int cursorY = 5;

    void moveCursor(ImageBuffer& ib, int x, int y);
    void drawUI(ImageBuffer& buffer);

    int getCursorX();
    int getCursorY();

    void remove();


private:
    TextBuffer& tb;
};
#endif
