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
    // to not let cursor escape to void while changing size
    if (cursorX > buffer.dimY)
        cursorX = buffer.dimY - 1;

    if (cursorY > buffer.dimX)
        cursorY = buffer.dimX - 1;   


    updateTextDimensions();
    std::vector<std::vector<char>>& metrix = tb->getMatrix(0, textHeight, textWidth);

    // std::vector<std::vector<char>> metrix = {{'h', 'e', 'l', 'l', 'o'}, {'w', 'o', 'r', 'l', 'd'}};

    for (int i = 0; i < metrix.size(); ++i) {
        for (int j = 0; j < metrix[0].size(); ++j) {
             buffer.change(i + textX, j + textY, metrix[i][j]);
        }
    }

    buffer.change(cursorX, cursorY, Mappings::CURSOR);
}


void UserI::remove() {
    tb->deleteChar(cursorY, cursorX);
}

UserI::UserI(TextBuffer* tb) {
    this->tb = tb;
    updateTextDimensions();
}

void UserI::updateTextDimensions() {
    this->textX = 0;
    this->textY = 0;
    this->textHeight = ImageBuffer::getConsoleHeight() - textX;
    this->textWidth = ImageBuffer::getConsoleWidth() - textY;
}
