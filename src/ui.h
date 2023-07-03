#ifndef UI

#define UI

#include "imageBuffer.h"
// #include "myTextBuffer.h"
#include "textBuffer.h"

class UserI {

const static char EMPTY = ' ';
const static char CURSOR = '#';
public:

    UserI(TextBuffer* tb);

    int cursorX = 5;
    int cursorY = 5;

    void moveCursor(ImageBuffer& ib, int x, int y);
    void drawUI(ImageBuffer& buffer);

    int getCursorX();
    int getCursorY();
    void remove();
    void updateTextDimensions();

private:
    TextBuffer* tb;
    int textX;
    int textY;
    int textHeight;
    int textWidth;
};

#endif
