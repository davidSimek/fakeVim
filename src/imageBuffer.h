#include <memory>
#include <vector>
#include <string>

#ifndef TEXT_BUFFER_H

#define TEXT_BUFFER_H


class ImageBuffer{
public:
    ImageBuffer(const int X, const int Y);
    std::vector<std::vector<char>>& getRef();
    void empty();
    void change(int x, int y, const char character);
    void resize();
    void getCString(char* current);
    size_t determineSize();
    static int getConsoleWidth();
    static int getConsoleHeight();

    int dimX;
    int dimY;
private:
    std::vector<std::vector<char>> buffer; 
};

#endif
