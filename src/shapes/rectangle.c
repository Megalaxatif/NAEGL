#include "shapes/rectangle.h"

#include <stdlib.h>

#include "global.h"
#include "error.h"
#include "settings.h"

Rectangle *createRectangle(double x, double y, double w, double h, GuiContext *gui_context, ssize_t flags) // TODO: use flags in settings
{
    if (x < 0 || y < 0 || w <= 0 || h <= 0 || !gui_context)
    {
        perror("Error: createRectangle, invalid arg");
        return NULL;
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

    r->settings = CreateDefaultRectangleSettings(w, h, gui_context);

    return r;
}

int destroyRectangle(Rectangle *rectangle)
{
    if (!rectangle)
        return ERR_OK;

    free(rectangle);

    return ERR_OK;
}
