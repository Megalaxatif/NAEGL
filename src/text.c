#include "text.h"

#include <stdlib.h>

#include "global.h"
#include "error.h"
#include "string.h"
#include "settings.h"

Text *CreateText(const char *text, GuiContext *gui_context, ssize_t flags)
{
    if (!gui_context)
    {
        perror("Error: createText, invalid arg");
        return NULL;
    }

    TextSettings *settings;

    if (!(settings = CreateTextSettings(gui_context, flags)))
    {
        perror("Error: CreateText, can't generate settings");
        return NULL;
    }

    if (!text)
        text = strdup(DEFAULT_TEXT_TEXT);
    else
        text = strdup(text);

    Text *t = malloc(sizeof(Text));

    t->text = text;
    t->settings = settings;

    return t;
}

int DestroyText(Text *text){}
