#include "textBuffer.h"
#include "ui.h"

#ifndef KEY_HANDLER_H

#define KEY_HANDLER_H

class KeyHandler {
public:
    KeyHandler(UserI* ui);
    void apply(TextBuffer& tb, int key, bool& typed, int& counter); 
private:
    UserI* ui;
};

#endif // !KEY_HANDLER
