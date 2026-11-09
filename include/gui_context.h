#pragma once

#include "settings.h"
#include "layout.h"

typedef struct GuiContext {
    SDL_Window *window;
    SDL_Renderer *renderer;
    GuiContextSettings *settings;
    WidgetSettingsArray *widget_settings;
    size_t nb_widget_settings;
    Layout *layouts;
    size_t nb_layout;
    LayoutSettingsArray *layout_settings;
    size_t nb_layout_settings;
    // shaders;
    size_t nb_shader;
} GuiContext;

GuiContext *createGuiContext(SDL_Window *window, SDL_Renderer *renderer, GuiContextSettings *settings);
int destroyGuiContext(GuiContext *gui_context);
int updateGuiContext(GuiContext *gui_context);
