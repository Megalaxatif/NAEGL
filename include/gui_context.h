#pragma once

#include "settings.h"
#include "layout.h"

typedef struct GuiContext {
	SDL_Window *window;
	SDL_Renderer *renderer;
	GuiContextSettings *settings;
	Layout *layouts;
	size_t nb_layout;
	// shaders;
} GuiContext;

GuiContext *createGuiContext(SDL_Window *window, SDL_Renderer *renderer, GuiContextSettings *settings);
int destroyGuiContext(GuiContext *gui_context);
int updateGuiContext(GuiContext *gui_context);
