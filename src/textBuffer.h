#include <string>
#include <vector>

#ifndef TEXT_BUFFER_H

#define TEXT_BUFFER_H

class TextBuffer {
    std::vector<std::string> buffer;

    void add(char key, int X, int Y);
    void clear(int X, int Y);

    std::string& getLine(int lineNumber, int length);
};

#endif

