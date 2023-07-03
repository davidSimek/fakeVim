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
#include "textBuffer.h"

int main() {
    // setup reading keys
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    set_escdelay(50);

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

    std::string initText = "Hello fake Vim!, Hello fake Vim!, Hello fake Vim!, Hello fake Vim!, Hello fake Vim!, Hello fake Vim!, Hello fake Vim!, Hello fake Vim!, ";
    // holds text you are editing
    TextBuffer* tb = new TextBuffer(initText);

    // abstraction over UI like cursor, background ...
    UserI* ui = new UserI(tb);
    KeyHandler keyHandler(ui);

    // actual printable buffer
    char* buffer  = new char[ib.determineSize()];

    
    // key reading thread
    std::thread keyListener([&]() {
        KeyHandler::runListener(shouldRun, key, counter, typed);
    });

    while (shouldRun) {


        // timing
        std::this_thread::sleep_for(std::chrono::milliseconds(30));

        // resolves if it needs to update, if so, updates ui
        keyHandler.apply(ib, key, typed, counter, canSkip);

        int currentWidth, currentHeight;
        getmaxyx(stdscr, currentHeight, currentWidth);

        if (currentWidth != ib.dimX + 1 || currentHeight != ib.dimY) {
            ib.resize(currentWidth - 1, currentHeight);
            delete[] buffer;
            buffer = new char[ib.determineSize()];
            canSkip = false;
        }

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
    delete tb;
    keyListener.join();
    endwin();
    return 0;
}
