#include "textBuffer.h"
#include "ui.h"
#include "keyHandler.h"
#include "ncurses.h"


void KeyHandler::render(TextBuffer& tb, int key, bool& typed, int& counter) {
    switch (key) {
        case 'l':
            ui->moveCursor(tb, 0, 1);
            break;
        case 'h':
            ui->moveCursor(tb, 0, -1);
            break;
        case 'k':
            ui->moveCursor(tb, -1, 0);
            break;
        case 'j':
            ui->moveCursor(tb, 1, 0);
            break;
    }
    typed = false;
    counter = 0;
}

KeyHandler::KeyHandler(UserI* ui) {
   this->ui = ui;
}
