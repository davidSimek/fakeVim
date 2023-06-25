#include "textBuffer.h"
#include "ui.h"

#ifndef KEY_HANDLER

#define KEY_HANDLER

#define KEY_HANDLER
class KeyHandler {
public:
    KeyHandler(UserI* ui);
    void render(TextBuffer& tb, int key, bool& typed, int& counter); 
private:
    UserI* ui;
};

#endif // !KEY_HANDLER
