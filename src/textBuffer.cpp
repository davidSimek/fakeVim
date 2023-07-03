#include "textBuffer.h"
#include <string>
#include <vector>
#include "mappings.h"


/*
std::vector<std::vector<char>>& TextBuffer::getMatrix(int firstLine, int height, int widht) {
    int linesCount = 0;
    for (std::string line : lines) {
        int charCount;
        for (char character : line) {
            if (charCount == widht) {
                formatedLines.emplace_back();
                ++linesCount;
                if (linesCount == height) {
                    return formatedLines;
                }
            }
            formatedLines[linesCount].emplace_back(character);
            ++charCount;
        }
        formatedLines.emplace_back();
        ++linesCount;
        if (linesCount == height) {
            break;
        }
    }
    return formatedLines;
}
*/

// this is last one
/*
std::vector<std::vector<char>>& TextBuffer::getMatrix(int firstLine, int height, int width) {
    int linesCount = firstLine;
    int charCount = 0;

    // Clear the existing content of formatedLines
    formatedLines.clear();

    for (std::string line : lines) {
        for (char character : line) {
            if (charCount == width) {
                formatedLines.emplace_back();
                ++linesCount;
                if (linesCount == height) {
                    return formatedLines;
                }
                charCount = 0;  // Reset charCount for the new line
            }
            formatedLines[linesCount].push_back(character);
            ++charCount;
        }
        formatedLines.emplace_back();
        ++linesCount;
        if (linesCount == height) {
            break;
        }
        charCount = 0;  // Reset charCount for the new line
    }

    return formatedLines;
}
*/

// final????

std::vector<std::vector<char>>& TextBuffer::getMatrix(int firstLine, int height, int width) {
    int linesCount = firstLine;
    int charCount = 0;

    formatedLines.clear();
    formatedLines.resize(height, std::vector<char>(width, Mappings::EMPTY));

    for (const std::string& line : lines) {
        for (char character : line) {
            if (charCount == width) {
                ++linesCount;
                if (linesCount == height) {
                    return formatedLines;
                }
                charCount = 0;  // reset charCount for the new line
            }
            formatedLines[linesCount][charCount] = character;
            ++charCount;
        }
        ++linesCount;
        if (linesCount == height) {
            break;
        }
        charCount = 0;  // reset charCount for the new line
    }

    return formatedLines;
}


/*
std::vector<std::vector<char>>& TextBuffer::getMatrix(int firstLine, int height, int width) {
    int linesCount = firstLine;
    int charCount = 0;

    for (std::string line : lines) {
        for (char character : line) {
            if (charCount == width) {
                formatedLines.emplace_back();
                ++linesCount;
                if (linesCount == height) {
                    return formatedLines;
                }
                charCount = 0;  // Reset charCount for the new line
            }
            formatedLines[linesCount].emplace_back(character);
            ++charCount;
        }
        formatedLines.emplace_back();
        ++linesCount;
        if (linesCount == height) {
            break;
        }
        charCount = 0;  // Reset charCount for the new line
    }

    return formatedLines;
}
*/




void TextBuffer::addChar(char key, int line, int character) {
    if (line >= lines.size() - 1 || line < 0) {
        return;
    }

    if (character >= lines[line].length() || character < 0) {
        return;
    }

    
     lines[line][character] = key;
}


void TextBuffer::deleteChar(int line, int character) {
    if (line >= lines.size() - 1 || line < 0) {
        return;
    }

    if (character >= lines[line].length() || character < 0) {
        return;
    }

    lines[line].erase(character, 1);
}

TextBuffer::TextBuffer(std::string initText) {
    this->lines.push_back(initText);
}
