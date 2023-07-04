#include "ui.h"
#include "imageBuffer.h"
#include <curses.h>
#include "mappings.h"

void UserI::moveCursor(int x, int y){
    if (cursorCharacter + x < 0 ||
        cursorCharacter + x >= ib->dimX ||
        cursorLine + y < 0 ||
        cursorLine + y >= ib->dimY) {
        return;
    } 
    cursorCharacter += x;
    cursorLine += y;
}

void UserI::drawUI() {
    // to not let cursor escape to void while changing size
    if (cursorCharacter > ib->dimX)
        cursorCharacter = ib->dimX - 1;

    if (cursorLine > ib->dimY)
        cursorLine = ib->dimY - 1;   


    updateTextDimensions();
    std::vector<std::vector<char>>& metrix = tb->getMatrix(0, textHeight, textWidth);

    for (int i = 0; i < metrix.size(); ++i) {
        for (int j = 0; j < metrix[i].size(); ++j) {
            // ib->change(i + textX, j + textY, 'h');
            ib->change(j + textX, i + textY, metrix[i][j]);
        }
    }

    ib->change(cursorCharacter, cursorLine, Mappings::CURSOR);
    ib->change(20, 20, std::to_string(cursorCharacter)[0]);
    ib->change(22, 20, std::to_string(cursorLine)[0]);

    ib->change(20, 23, std::to_string(ib->getConsoleWidth())[0]);
    ib->change(22, 23, std::to_string(ib->getConsoleHeight())[0]);
}


void UserI::remove() {
    tb->deleteChar(cursorLine, cursorCharacter);
    moveCursor(-1, 0);
}

void UserI::add(char key) {
    tb->addChar(key, cursorLine, cursorCharacter);
}

UserI::UserI(TextBuffer* tb, ImageBuffer* ib) {
    this->tb = tb;
    this->ib = ib;
    updateTextDimensions();
}

void UserI::updateTextDimensions() {
    this->textX = 0;
    this->textY = 0;
    this->textHeight = ImageBuffer::getConsoleHeight() - textX;
    this->textWidth = ImageBuffer::getConsoleWidth() - textY;
}

void UserI::newLine() {
    tb->insertLine(cursorLine);
    moveCursor(0, 1);
}
