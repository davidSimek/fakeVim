#include "ui.h"
#include "textBuffer.h"
#include <curses.h>
#include "mappings.h"

void UserI::moveCursor(ImageBuffer& buffer, int x, int y){
    if (cursorX + x < 0 ||
        cursorX + x > buffer.dimX - 1 ||
        cursorY + y < 0 ||
        cursorY + y > buffer.dimY - 1) {
        return;
    } 
    cursorX += x;
    cursorY += y;
}

void UserI::drawUI(ImageBuffer& buffer) {
    buffer.change(cursorX, cursorY, Mappings::CURSOR);
}

