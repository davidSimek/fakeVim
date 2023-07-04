#include <vector>
#include <string>
#include "imageBuffer.h"
#include <cstring>
#include "mappings.h"
#include <sys/ioctl.h>
#include <unistd.h>


ImageBuffer::ImageBuffer (const int x,const int y) {
    dimX = x;
    dimY = y;
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, Mappings::EMPTY));
}


std::vector<std::vector<char>>& ImageBuffer::getRef(){
    return buffer;
}


void ImageBuffer::empty() {
    buffer = std::vector<std::vector<char>>(dimY, std::vector<char>(dimX, Mappings::EMPTY));
}


void ImageBuffer::change(int x, int y, const char character) {
    if (x >= dimX || y >= dimY || x < 0 || y < 0){
        return;
    }
    buffer[y][x] = character;
    // buffer[y][x] = character;
}
void ImageBuffer::resize(int newX, int newY) {
    dimX = newX;
    dimY = newY;
    // dont need to use probably, I am too lazy now to care
    this->empty();
}


size_t ImageBuffer::determineSize() {
    return dimX * dimY + dimY + 1;
}


void ImageBuffer::getCString(char* current){
    for (const std::vector<char>& line : buffer) {
        for (const char& character : line) {
            *current = character;
            current++;
        }
        *current = '\n';
        current++;
    }
    *current = '\0';
}


int ImageBuffer::getConsoleWidth() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    }
    return 10;  // Default width if unable to determine
}


int ImageBuffer::getConsoleHeight() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_row;
    }
    return 10;  // Default height if unable to determine
}
