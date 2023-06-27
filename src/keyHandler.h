#include "imageBuffer.h"
#include "ui.h"

#ifndef KEY_HANDLER_H

#define KEY_HANDLER_H

class KeyHandler {
public:
    KeyHandler(UserI* ui);
    void apply(ImageBuffer& tb, int key, bool& typed, int& counter, bool& canSkip); 
    static void runListener(bool& shouldRun, int& key, int& counter, bool& typed);
private:
    UserI* ui;
};

#endif // !KEY_HANDLER
