#include <string>

#ifndef MAPPINGS_H

#define MAPPINGS_H

class Mappings {
public:
    // visuals
    static char CURSOR;
    static char EMPTY;

    // controls
    static char UP;
    static char DOWN;
    static char LEFT;
    static char RIGHT;


    static void loadConfig();
private:
    static bool trySet(const char* name, char value);
    static void processLine(std::string line);
};
 

#endif
