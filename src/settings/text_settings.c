#include "settings.h"

TextSettings *CreateTextSettings(Layout *layout, ssize_t flags) // TODO
{
    if (!layout || !layout->gui_context)
    {
        perror("Error: createTextSettings, arg NULL");
        return NULL;
    }

	GuiContext *gui_context = layout->gui_context;

    TTF_Font *font = TTF_OpenFont(DEFAULT_TEXT_FONT_PATH, DEFAULT_TEXT_FONT_SIZE); // DON'T forget to close
    if (!font)
	{
        perror("Error: CreateTextSettings, TTF_OpenFont failed");
        return NULL;
    }

    RectangleSettings *t = malloc(sizeof(TextSettings));

	t->font = font;
    t->size = DEFAULT_TEXT_FONT_SIZE;

    SDL_Surface *surface = TTF_RenderUTF8_Blended(font, DEFAULT_TEXT_TEXT, DEFAULT_TEXT_FONT_COLOR);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(gui_context->renderer, surface);
	
	SDL_FreeSurface(surface);

    t->texture = texture;

	t->padding_x = DEFAULT_TEXT_PADDING_X;
	t->padding_y = DEFAULT_TEXT_PADDING_Y;

    t->flags = flags;
	t->layout = layout;

    return t;
}

int DestroyTextSettings(TextSettings *settings)
{
	if (!settings)
	{
		return ERR_INVALID_ARGUMENT;
	}

	return ERR_OK;
}
