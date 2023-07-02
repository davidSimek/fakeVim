#include "myTextBuffer.h"
#include <string>
#include <vector>

std::vector<std::vector<char>>& TextBuffer::getString(int firstLine, int height, int widht) {
    int linesCount = 0;
    for (std::string line : lines) {
        int charCount;
        for (char character : line) {
            if (charCount == widht) {
                ++linesCount;
                if (linesCount == height) {
                    return formatedLines;
                }
            }
            formatedLines[linesCount].emplace_back(character);
            ++charCount;
        }
        ++linesCount;
        if (linesCount == height) {
            break;
        }
    }
    return formatedLines;
}


void TextBuffer::addChar(char key, int line, int character) {
    if (line >= lines.size() - 1) {
        return;
    }

    if (character >= lines[line].length()) {
        return;
    }

    lines[line][character] = key;
}


void TextBuffer::deleteChar(int line, int character) {
    if (line >= lines.size() - 1) {
        return;
    }

    if (character >= lines[line].length()) {
        return;
    }

    lines[line].erase(character, 1);
}
