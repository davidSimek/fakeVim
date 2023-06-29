#include "mappings.h"
#include <iostream>
#include <fstream>
#include "cstring"
#include "log.h"

char Mappings::CURSOR = '#';
char Mappings::EMPTY = ' ';
char Mappings::UP = 'k';
char Mappings::DOWN = 'j';
char Mappings::LEFT = 'h';
char Mappings::RIGHT = 'l';
char Mappings::INPUT_MODE = 'i';
char Mappings::NORMAL_MODE = 'n';

void Mappings::loadConfig() {

    const char* homeDir = getenv("HOME");
    std::string filePath = std::string(homeDir) + "/.config/fakeVim/init.conf";

    std::ifstream ifs(filePath.c_str());
    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            // comments
            if (line[0] == '#' || strcmp(line.c_str(), "") == 0)
                continue;

            Mappings::processLine(line.c_str());
        }
        ifs.close();
    } else {
        Log::addError("couldn't open config file");
        // error: couldn't open
    }    
}

void Mappings::processLine(std::string line) {
    std::string variable;
    char value;

    size_t spacePos = line.find(' ');
    
    if (spacePos != std::string::npos) {
        variable = line.substr(0, spacePos);
    } else {
        Log::addError("you probably forgot to assign character for value");
        return;
    }

    // Find the position of the character after the first word
    size_t firstCharPos;
    if (spacePos != std::string::npos) {
        firstCharPos = spacePos + 1;
    } else {
        Log::addError("there is probably no character set for one or more values");
        return;
    }
    // Extract the first character after the word
    if (firstCharPos < line.length()) {
        value = line[firstCharPos];
    } else {
        Log::addError("there is probably no character set for one or more values");
        return;
    }

    Mappings::trySet(variable.c_str(), value); 
}

bool Mappings::trySet(const char* name, char value) {
    Log::addError((std::string(name) + " " + value).c_str());
    if (strcmp(name, "cursor") == 0){
        Mappings::CURSOR = value;
        return true;
    }
    if (strcmp(name, "empty") == 0){
        Mappings::EMPTY = value;
        return true;
    }
    if (strcmp(name, "up") == 0){
        Mappings::UP = value;
        return true;
    }
    if (strcmp(name, "down") == 0){
        Mappings::DOWN = value;
        return true;
    }
    if (strcmp(name, "left") == 0){
        Mappings::LEFT = value;
        return true;
    }
    if (strcmp(name, "right") == 0){
        Mappings::RIGHT = value;
        return true;
    }
    if (strcmp(name, "inputMode")) {
        Mappings::INPUT_MODE = value;
        return true;
    }
    if (strcmp(name, "normalMode")) {
        Mappings::INPUT_MODE = value;
        return true;
    }
    Log::addError("it looks like you are trying to asign character to non-existent value");
    return false;
}
