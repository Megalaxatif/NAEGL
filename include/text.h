#include "settings.h"

typedef struct Text {
    TextSettings *settings;
    char *text;
} Text;

Text *createText(const char *text, TextSettings *settings, GuiContext *gui_context);
int destroyText(Text *text);
