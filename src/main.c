#include <stdio.h>
#include "error.h"

int main(void)
{
    // Simulating a pipeline to create a button

    // 1 Create gui_context
    GuiContext *gui_context = createGuiContext(&window, &renderer, NULL);

    // 2 create a rectangle
    Rectangle rect = CreateRectangle(0.1, 0.1, 0.1, 0.2, gui_context, 0);

    // 3 create a widget
    // rect could be NULL, if so we apply a default rect
    // TODO create a layout by default which takes the whole screen
    CreateWidget(WIDGET_TYPE_BUTTON, rect, gui_context, 0);

    // PROBLEM:
    // We use CreateRectangle to call CreateWidget which is what we want
    // But what do we do if their flags are different?
    // Maybe propagate the parent ones, here set the rect flags to the widget ones

    printf("GOOD ENDING\n");

    return ERR_OK;
}
