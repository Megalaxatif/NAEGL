#include <stdio.h>
#include "error.h"

int main(void)
{

    // TODO create a layout by default which takes the whole screen
    GuiContext *gui_context = createGuiContext(&window, &renderer, NULL);

    // ajouter widget sur layout specifique
    LayoutCreateWidget(WidgetType *widgetType, Layout *layout, ssize_t default_flags);
    LayoutAddWidget(Widget *widget, Layout *layout);
    // ajouter widget sur layout 0
    Widget *widget = createWidget(widgetType, rect, gui_context, default_flags);

    printf("GOOD ENDING\n");

	return ERR_OK;
}
