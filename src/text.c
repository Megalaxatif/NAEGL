#include "text.h"

#include <stdlib.h>

#include "global.h"
#include "error.h"
#include "string.h"

Text *createText(const char *text, TextSettings *settings, GuiContext *gui_context)
{
    if (!gui_context)
    {
        perror("Error: createText, invalid arg");
        return NULL;
    }

    if (settings)
    {
        if (settings->gui_context != gui_context)
        {
            perror("Error: createText, conflicting gui_context");
            return NULL;
        }
    }
    else
    {
        if (!(settings = createDefaultText(gui_context)))
        {
            perror("Error: createText, can't generate default settings");
            return NULL;
        }
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

TextSettings *createDefaultTextSettings(GuiContext *gui_context) // TODO
{
	if (!gui_context)
		return NULL;

	return NULL;
}

int destroyText(Text *text){}
