#include "rectangle.h"

#include "settings.h"
#include "error.h"

RectangleSettings *CreateRectangleSettings(double w, double h, GuiContext *gui_context, ssize_t flags)
{
    if (!gui_context)
    {
        perror("Error: createRectangleSettings, gui_context NULL");
        return NULL;
    }

    RectangleSettings *r = malloc(sizeof(RectangleSettings));

    int win_w;
    int win_h;
    SDL_GetWindowSize(gui_context->window, &win_w, &win_h);
    SDL_Texture *texture = SDL_CreateTexture(
            gui_context->renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            w * win_w,
            h * win_h
            );

    Uint8 red = DEFAULT_RECTANGLE_TEXTURE_COLOR.r;
    Uint8 green = DEFAULT_RECTANGLE_TEXTURE_COLOR.g;
    Uint8 blue = DEFAULT_RECTANGLE_TEXTURE_COLOR.b;
    Uint8 alpha = DEFAULT_RECTANGLE_TEXTURE_COLOR.a;

    SDL_SetRenderTarget(gui_context->renderer, texture); // Add color to the texture
    SDL_SetRenderDrawColor(gui_context->renderer, red, green, blue, alpha);
    SDL_RenderClear(gui_context->renderer);
    SDL_SetRenderTarget(gui_context->renderer, NULL);

    r->border_color = DEFAULT_RECTANGLE_BORDER_COLOR;
    r->texture = texture;

    r->corner_radius = DEFAULT_RECTANGLE_CORNER_RADIUS;
    r->border_width = DEFAULT_RECTANGLE_BORDER_WIDTH;
    r->gui_context = gui_context;

    r->flags = flags;

    return r;
}
