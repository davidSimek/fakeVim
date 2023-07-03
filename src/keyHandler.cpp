#include "imageBuffer.h"
#include "modes.h"
#include "ui.h"
#include "keyHandler.h"
#include "ncurses.h"
#include "mappings.h"
#include <curses.h>


void KeyHandler::apply(ImageBuffer& ib, int key, bool& typed, int& counter, bool& canSkip) {
    if (key != -1) {
        canSkip = false;
    } else {
        canSkip = true;
        return;
    }

    // escape
    if (key == Mappings::NORMAL_MODE) {
        mode = Modes::NORMAL;
        typed = false;
        counter = -1;
        return;
    }
    if (key == Mappings::INPUT_MODE) {
        mode = Modes::INPUT;
        typed = false;
        counter = -1;
        return;
    }

    if (mode == Modes::NORMAL) {
        if      (key == Mappings::RIGHT)
            ui->moveCursor(ib,  0,  1);

        else if (key == Mappings::LEFT)
            ui->moveCursor(ib,  0, -1);

        else if (key == Mappings::UP)
            ui->moveCursor(ib, -1,  0);

        else if (key == Mappings::DOWN)
            ui->moveCursor(ib,  1,  0);
        else if (key == Mappings::REMOVE)
                ui->remove();
    } else if (mode == Modes::INPUT) {
        ui->add(key);    
        ui->cursorY++;
    }
    
    typed = false;
    counter = -1;
}

KeyHandler::KeyHandler(UserI* ui) {
   this->ui = ui;
}

void KeyHandler::runListener(bool& shouldRun, int& key, int& counter, bool& typed) {
    int realkey;
        while (shouldRun) {
            realkey = getch();

            // make key pressed longer 
            if (realkey == -1) {
                typed = false;
            } else {
                typed = true;
            }

            if (typed) {
                counter = 1000000;
                key = realkey;
            } else if(counter >= 0){
                --counter;
            }

            if (counter <= 0) {
                key = realkey;
            }
        }
}
