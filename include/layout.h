#pragma once

#include "settings.h"
#include "gui_context.h"

typedef struct Layout {
	LayoutSettings *settings;
	Widget *widgets;
} Layout;

Layout *createLayout(LayoutSettings *settings, GuiContext *gui_context);
int destroyLayout(Layout *layout);
