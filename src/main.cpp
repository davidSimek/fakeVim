#include <algorithm>
#include <curses.h>
#include <iostream>
#include <iterator>
#include <mutex>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include "imageBuffer.h"
#include "ui.h"
#include "keyHandler.h"
#include "mappings.h"
#include "log.h"

int main() {
    // setup reading keys
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    // set mapping from config file
    Mappings::loadConfig();


    // main loop control
    bool shouldRun = true;
    bool canSkip = false;

    // key reading handling
    int key;
    bool typed = true;
    int counter = 1000000;

    // vector<vector<char>> holding image
    ImageBuffer ib(
        ImageBuffer::getConsoleWidth() - 1,
        ImageBuffer::getConsoleHeight()
    );

    // abstraction over UI like cursor, background ...
    UserI* ui = new UserI();

    // actual printable buffer
    char* buffer  = new char[ib.determineSize()];

    KeyHandler keyHandler(ui);
    
    // key reading thread
    std::thread keyListener([&]() {
        KeyHandler::runListener(shouldRun, key, counter, typed);
    });

    while (shouldRun) {
        // timing
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        // draw to buffer
        

        keyHandler.apply(ib, key, typed, counter, canSkip);

        if (canSkip) {
            continue;
        }

        // wrapper for calling functions rendering to ib
        ui->drawUI(ib);

        // pass ib to buffer
        ib.getCString(buffer);

        // filling ib woth Mappings::EMPTY
        ib.empty();

        clear();
        printw("%s\n", buffer);
    }

    // cleanup
    delete[] buffer;
    delete ui;
    keyListener.join();
    endwin();
    return 0;
}
