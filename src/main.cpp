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

int main() {
    bool shouldRun = true;

    int key;
    int currentkey = key;

    bool typed = true;
    int counter = 1000000;

    TextBuffer tb(20, 30);

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

    while (shouldRun) {
        // timing
        std::this_thread::sleep_for(std::chrono::milliseconds(20));

        // drawing
        clear();
        tb.change(10, 15, 'r');
        const char* buffer = tb.getCString();
        printw("%s", buffer);
        delete[] buffer;
    }

    keyListener.join();
    endwin();
    return 0;
}
