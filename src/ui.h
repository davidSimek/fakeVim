#ifndef UI

#define UI

#include "imageBuffer.h"
// #include "myTextBuffer.h"
#include "textBuffer.h"

class UserI {

const static char EMPTY = ' ';
const static char CURSOR = '#';
public:

    UserI(TextBuffer* tb, ImageBuffer* ib);

    int cursorLine = 5;
    int cursorCharacter = 5;

    void moveCursor(int x, int y);
    void drawUI();

    int getCursorX();
    int getCursorY();
    void remove();
    void add(char key);
    void updateTextDimensions();
    void newLine();

private:
    TextBuffer* tb;
    ImageBuffer* ib;
    int textX;
    int textY;
    int textHeight;
    int textWidth;
};

#endif
