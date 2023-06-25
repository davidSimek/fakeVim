#include <vector>
#include <string>
#include "textBuffer.h"
#include <cstring>

TextBuffer::TextBuffer (const int X,const int Y) {
    dimY = Y;
    dimX = X;
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, ' '));
}

std::vector<std::vector<char>>& TextBuffer::getRef() {
    return buffer;
}

void empty() {
 
}
void TextBuffer::change(int x, int y, const char character) {
    if (x >= dimX || y >= dimY){
        return;
    }
    buffer[x][y] = character;
}
void resize() {

}

const char* TextBuffer::getCString(){
    // get size of buffer needed
    size_t totalSize = 0;
    for (const std::vector<char>& row : buffer) {
            totalSize += row.size() + 1; // for the new line char
    }
    totalSize += 1;  // for null termunation

    // Create a buffer for the C-style string
    char* cstr = new char[totalSize];
    char* current = cstr;

    // Copy the strings and add newline characters
    for (const std::vector<char>& row : buffer) {
        for (const char& str : row) {
            *current = str;
            current++;
        }
        *current = '\n';
        current++;
    }
    *current = '\0'; // Null terminate the string    

    return cstr;
}
