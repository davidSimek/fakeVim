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
#include "textBuffer.h"
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
    const char* homeDir = getenv("HOME");
    std::string filePath = std::string(homeDir) + "/.config/fakeVim/init.conf";
    Mappings::loadConfig(filePath.c_str());


    bool shouldRun = true;

    // key reading handling
    int key;
    bool typed = true;
    int counter = 1000000;

    ImageBuffer tb(40, 40);
    UserI* ui = new UserI();
    char* buffer  = new char[tb.determineSize()];
    KeyHandler keyHandler(ui);
    
    std::thread keyListener([&]() {
        KeyHandler::runListener(shouldRun, key, counter, typed);
    });

    while (shouldRun) {
        // timing
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
        
        // draw to buffer
        keyHandler.apply(tb, key, typed, counter);
        ui->drawUI(tb);

        // pass tb to buffer
        tb.getCString(buffer);

        // filling tb woth Mappings::EMPTY
        tb.empty();

        clear();
        printw("%s\n", buffer);
        Log::printError();
    }
    delete[] buffer;
    delete ui;
    keyListener.join();
    endwin();
    return 0;
}
