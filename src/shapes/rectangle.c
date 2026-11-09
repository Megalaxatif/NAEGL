#include "shapes/rectangle.h"

#include <stdlib.h>

#include "global.h"
#include "error.h"

Rectangle *createRectangle(double x, double y, double w, double h, RectangleSettings *settings, GuiContext *gui_context)
{
    if (x < 0 || y < 0 || w <= 0 || h <= 0 || !gui_context)
    {
        perror("Error: createRectangle, invalid arg");
        return NULL;
    }

    if (settings)
    {
        if (settings->gui_context != gui_context)
        {
            perror("Error: createRectangle, conflicting gui_context");
            return NULL;
        }
    }
    else
    {
        if (!(settings = createDefaultRectangleSettings(w, h, gui_context)))
        {
            return NULL;
        }
    }

    Rectangle *r = malloc(sizeof(Rectangle));

    int win_w;
    int win_h;
    SDL_GetWindowSize(gui_context->window, &win_w, &win_h);

    r->absolute_x = x * win_w;
    r->absolute_y = y * win_h;
    r->absolute_w = w * win_w;
    r->absolute_h = h * win_h;

    r->x = x;
    r->y = y;
    r->w = w;
    r->h = h;

    r->settings = settings;

    return r;
}

RectangleSettings *createDefaultRectangleSettings(double w, double h, GuiContext *gui_context)
{
    if (!gui_context)
        return NULL;

    RectangleSettings *r = malloc(sizeof(RectangleSettings));

    r->border_color = COLOR_BLACK;

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

    SDL_SetRenderTarget(gui_context->renderer, texture); // Add color to the texture
    SDL_SetRenderDrawColor(gui_context->renderer, 200, 200, 200, 255);
    SDL_RenderClear(gui_context->renderer);
    SDL_SetRenderTarget(gui_context->renderer, NULL);

    r->texture = texture;

    r->corner_radius = DEFAULT_RECTANGLE_CORNER_RADIUS;
    r->border_width = DEFAULT_RECTANGLE_BORDER_WIDTH;
    r->gui_context = gui_context;

    return NULL;
}

int destroyRectangle(Rectangle *rectangle)
{
    if (!rectangle)
        return ERR_OK;

    free(rectangle);

    return ERR_OK;
}
