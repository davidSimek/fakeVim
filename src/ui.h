#include "textBuffer.h"

class UI {

const static char EMPTY = ' ';
const static char CURSOR = '#';

private:
    int cursorX;
    int cursorY;
public:
    void moveCursor(TextBuffer& buffer, int x, int y);
};
