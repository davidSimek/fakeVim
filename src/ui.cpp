#include "ui.h"
#include "imageBuffer.h"
#include <curses.h>
#include "mappings.h"

void UserI::moveCursor(ImageBuffer& ib, int x, int y){
    if (cursorX + x < 0 ||
        cursorX + x >= ib.dimY ||
        cursorY + y < 0 ||
        cursorY + y >= ib.dimX) {
        return;
    } 
    cursorX += x;
    cursorY += y;
}

void UserI::drawUI(ImageBuffer& buffer) {
    buffer.change(cursorX, cursorY, Mappings::CURSOR);
}

