#include "mappings.h"
#include <iostream>
#include <fstream>

const char Mappings::CURSOR = '#';
const char Mappings::EMPTY = ' ';
const char Mappings::UP = 'k';
const char Mappings::DOWN = 'j';
const char Mappings::LEFT = 'h';
const char Mappings::RIGHT = 'l';

void Mappings::loadConfig(const char* location) {
    std::ifstream ifs(location);
    if (ifs.is_open()) {
        std::string line;
        while (std::getline(ifs, line)) {
            // line is const char*
        }
        ifs.close();
    } else {
        // error: couldn't open
    }    
}
