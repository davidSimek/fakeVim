#ifndef LOG_H

#include <sstream>

#define LOG_H

class Log {
public:
    static void addError(const char* err);
    static void printError();
private:
    static std::stringstream error;
};

#endif

