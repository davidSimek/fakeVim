#include "log.h"
#include <curses.h>
#include <iostream>
#include <sstream>

std::stringstream Log::error = std::stringstream();

void Log::addError(const char* err) {
    error << err << '\n';
}

void Log::printError(){
    printw("Errors:\n%s", Log::error.str().c_str());
}

