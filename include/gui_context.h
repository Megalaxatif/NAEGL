#pragma once

#include "settings.h"
#include "layout.h"
#include "arrays.h"

typedef struct GuiContext {
    SDL_Window *window;
    SDL_Renderer *renderer;
    GuiContextSettings *settings;
    LayoutArray *layout_array;
    // shaders;
    // TODO: add ShaderArray
    //ShaderArray *shader_array;
} GuiContext;

GuiContext *CreateGuiContext(SDL_Window *window, SDL_Renderer *renderer, GuiContextSettings *settings);
int DestroyGuiContext(GuiContext *gui_context);

int GuiContextSetDefaultLayoutSettings(GuiContext* context, LayoutSettings *settings); // COPY the given settings into the Layout settings of the gui context

int UpdateGuiContext(GuiContext *gui_context);
