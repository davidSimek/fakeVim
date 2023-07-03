#ifndef MY_TEXT_BUFFER_H

#include <string>
#include <string_view>
#include <vector>
#include <sstream>

#define MY_TEXT_BUFFER_H

class MyTextBuffer {
public:
    void addChar(char key, int line, int character);
    void deleteChar(int line, int character);

    std::vector<std::vector<char>>& getString(int firstLine, int height, int widht);


private:
    std::vector<std::string> lines;
    std::vector<std::vector<char>> formatedLines;

    void resizeBuffer();
};

#endif

