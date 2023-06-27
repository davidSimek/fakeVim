#include <vector>
#include <string>
#include "textBuffer.h"
#include <cstring>
#include "mappings.h"

ImageBuffer::ImageBuffer (const int x,const int y) {
    dimY = y;
    dimX = x;
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, Mappings::EMPTY));
}

std::vector<std::vector<char>>& ImageBuffer::getRef() {
    return buffer;
}

void ImageBuffer::empty() {
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, Mappings::EMPTY));
}
void ImageBuffer::change(int x, int y, const char character) {
    if (x > dimX || y > dimY || x < 0 || y < 0){
        return;
    }
    buffer[x][y] = character;
}
void resize() {

}

size_t ImageBuffer::determineSize() {
    return dimX * dimY + dimY + 1;
}

void ImageBuffer::getCString(char* current){
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
