#pragma once

#include "settings.h"

typedef struct Button {
    ButtonSettings *settings;
    State state;
} Button;

Button *CreateButton();
Button *CreateDefaultButton();
int DestroyButton(Button *button);
