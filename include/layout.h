#pragma once

#include "settings.h"
#include "gui_context.h"
#include "arrays.h"



typedef struct Layout {
    LayoutSettings *settings;
    WidgetArray *widget_array;
    GuiContext *gui_context;
} Layout;

Layout *CreateLayout(GuiContext *gui_context, int origin_y, int origin_y, int ssize_t flags);
int DestroyLayout(Layout *layout);

// COPY the given settings of the corresponding widget into the settings of the layout
int LayoutSetWidgetDefaultSettings(Layout* layout, WidgetSettings *settings, WidgetType *widgetType);

// create a widget, copy the corresponding default settings of the layout into it and add the widget to the layout
int LayoutCreateWidget(WidgetType *widgetType, Layout *layout, ssize_t flags);

int LayoutBindWidget(Widget *widget, Layout *layout); // add the widget in the given layout and remove it from the previous one
int LayoutUnbindWidget(Widget *widget); // bind the widget to the default layout

//------ PRIVATE FUNCTION ------
