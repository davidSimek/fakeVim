#include "ui.h"
#include "textBuffer.h"

void UI::moveCursor(TextBuffer& buffer, int x, int y){
    buffer.change(cursorX, cursorY, UI::EMPTY);  
    buffer.change(cursorX + x, cursorY + y, UI::CURSOR);   
}
