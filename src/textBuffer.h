#include <string>
#include <string_view>
#include <vector>
#include <sstream>

#ifndef TEXT_BUFFER_H

#define TEXT_BUFFER_H

class TextBuffer {
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

