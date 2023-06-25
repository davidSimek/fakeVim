#include <curses.h>
#include <iostream>
#include <iterator>
#include <mutex>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include "textBuffer.h"
#include "ui.h"
#include "keyHandler.h"

int main() {
    bool shouldRun = true;

    int key;
    int currentkey = key;

    bool typed = true;
    int counter = 1000000;

    TextBuffer tb(20, 20);

    // setup reading keys
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    std::thread keyListener([&]() {
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
    });

    UserI* ui = new UserI();
    char* buffer  = new char[tb.determineSize()];
    while (shouldRun) {
        // timing
        std::this_thread::sleep_for(std::chrono::milliseconds(20));

        KeyHandler keyHandler(ui);
        keyHandler.render(tb, key, typed, counter);

        // drawing
        clear();
        tb.getCString(buffer);
        tb.empty();


        printw("%s position is %d %d", buffer, ui->cursorX, ui->cursorY);
    }
    delete[] buffer;
    delete ui;
    keyListener.join();
    endwin();
    return 0;
}
