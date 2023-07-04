#ifndef TEXT_BUFFER_H

#include <string>
#include <string_view>
#include <vector>
#include <sstream>

#define TEXT_BUFFER_H

class TextBuffer {
public:

    TextBuffer(std::vector<std::string> initText);

    void addChar(char key, int line, int character);
    void deleteChar(int line, int character);

    std::vector<std::vector<char>>& getMatrix(int firstLine, int height, int widht);


private:
    std::vector<std::string> lines;
    std::vector<std::vector<char>> formatedLines;

    void resizeBuffer();
};

#endif

