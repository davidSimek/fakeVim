#include <vector>
#include <string>
#include "textBuffer.h"
#include <cstring>

TextBuffer::TextBuffer (const int x,const int y) {
    dimY = y;
    dimX = x;
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, ' '));
}

std::vector<std::vector<char>>& TextBuffer::getRef() {
    return buffer;
}

void TextBuffer::empty() {
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, ' '));
}
void TextBuffer::change(int x, int y, const char character) {
    if (x >= dimX || y >= dimY || x < 0 || y < 0){
        return;
    }
    buffer[x][y] = character;
}
void resize() {

}

size_t TextBuffer::determineSize() {
    return dimX * dimY + dimY + 1;
}

void TextBuffer::getCString(char* current){
    for (const std::vector<char>& row : buffer) {
        for (const char& ch : row) {
            *current = ch;
            current++;
        }
        *current = '\n';
        current++;
    }
    *current = '\0'; // Null terminate the string    
}
