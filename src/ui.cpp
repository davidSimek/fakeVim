#include "ui.h"
#include "textBuffer.h"
#include <curses.h>

void UserI::moveCursor(TextBuffer& buffer, int x, int y){
    if (cursorX + x < 0 ||
        cursorX + x > buffer.dimX - 1 ||
        cursorY + y < 0 ||
        cursorY + y > buffer.dimY - 1) {
        return;
    } 
    cursorX += x;
    cursorY += y;
    buffer.change(cursorX, cursorY, UserI::CURSOR);   
}

void UserI::drawUI(TextBuffer& buffer) {
    buffer.change(cursorX, cursorY, UserI::CURSOR);
}

