#include "textBuffer.h"
#include "ui.h"
#include "keyHandler.h"
#include "ncurses.h"
#include "mappings.h"


void KeyHandler::apply(TextBuffer& tb, int key, bool& typed, int& counter) {
    // I am not able to use switch because it requires mapping known in compile-time
    // (if I got it right)
     
    if      (key == Mappings::RIGHT)
        ui->moveCursor(tb,  0,  1);

    else if (key == Mappings::LEFT)
        ui->moveCursor(tb,  0, -1);

    else if (key == Mappings::UP)
        ui->moveCursor(tb, -1,  0);

    else if (key == Mappings::DOWN)
        ui->moveCursor(tb,  1,  0);
    
    typed = false;
    counter = -1;
}

KeyHandler::KeyHandler(UserI* ui) {
   this->ui = ui;
}
