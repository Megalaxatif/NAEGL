#pragma once

#include "settings.h"
#include "layout.h"

typedef struct GuiContext {
    SDL_Window *window;
    SDL_Renderer *renderer;
    GuiContextSettings *settings;
    LayoutArray *layout_array;
    // shaders;
    // TODO: add ShaderArray
    //ShaderArray *shader_array;
} GuiContext;

int GuiContextSetDefaultLayoutSettings(LayoutSettings *settings); // COPY the given settings into the settings of the gui context

GuiContext *CreateGuiContext(SDL_Window *window, SDL_Renderer *renderer, GuiContextSettings *settings);
int DestroyGuiContext(GuiContext *gui_context);
int UpdateGuiContext(GuiContext *gui_context);
