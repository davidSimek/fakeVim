#ifndef MAPPINGS_H

#include <string>

#define MAPPINGS_H

class Mappings {
public:
    // visuals
    static int CURSOR;
    static int EMPTY;

    // controls
    static int UP;
    static int DOWN;
    static int LEFT;
    static int RIGHT;
    static int REMOVE;

    // modes
    static int INPUT_MODE;
    static int NORMAL_MODE;


    static void loadConfig();
private:
    static bool trySet(const char* name, char value);
    static void processLine(std::string line);
};
 

#endif
