#include "ui.h"
#include "imageBuffer.h"
#include <curses.h>
#include "mappings.h"

void UserI::moveCursor(ImageBuffer& ib, int x, int y){
    if (cursorCharacter + x < 0 ||
        cursorCharacter + x >= ib.dimX ||
        cursorLine + y < 0 ||
        cursorLine + y >= ib.dimY) {
        return;
    } 
    cursorCharacter += x;
    cursorLine += y;
}

void UserI::drawUI(ImageBuffer& buffer) {
    // to not let cursor escape to void while changing size
    if (cursorCharacter > buffer.dimY)
        cursorCharacter = buffer.dimY - 1;

    if (cursorLine > buffer.dimX)
        cursorLine = buffer.dimX - 1;   


    updateTextDimensions();
    std::vector<std::vector<char>>& metrix = tb->getMatrix(0, textHeight, textWidth);

    for (int i = 0; i < metrix.size(); ++i) {
        for (int j = 0; j < metrix[0].size(); ++j) {
             buffer.change(i + textX, j + textY, metrix[i][j]);
        }
    }

    buffer.change(cursorCharacter, cursorLine, Mappings::CURSOR);
}


void UserI::remove() {
    tb->deleteChar(cursorCharacter, cursorLine);
}

void UserI::add(char key) {
    tb->addChar(key, cursorLine, cursorCharacter);
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
