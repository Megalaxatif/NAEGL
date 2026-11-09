#pragma once

#include "settings.h"

typedef struct Button {
	ButtonSettings *settings;
	State state;
} Button;

Button *createButton(WidgetSettings *settings);
Button *createDefaultButton();
int destroyButton(Button *button);
