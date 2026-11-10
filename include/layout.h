#pragma once

#include "settings.h"
#include "gui_context.h"

typedef struct Layout {
    LayoutSettings *settings;
    size_t capacity;
    size_t widget_count;
    Widget **widgets;
    GuiContext *gui_context;
} Layout;

typedef struct LayoutArray {
    size_t capacity;
    size_t count;
    Layout **layouts;
} LayoutArray;

Layout *CreateLayout(GuiContext *gui_context, ssize_t flags);
int DestroyLayout(Layout *layout);

// COPY the given settings of the corresponding widget into the settings of the layout
int LayoutSetDefaultSettings(WidgetSettings *settings, WidgetType *widgetType, Layout* layout);

// create a widget, copy the corresponding default settings of the layout into it and add the widget to the layout
int LayoutCreateWidget(WidgetType *widgetType, Layout *layout, ssize_t flags);

int LayoutBindWidget(Widget *widget, Layout *layout); // add the widget in the given layout and remove it from the previous one
int LayoutUnbindWidget(Widget *widget); // bind the widget to the default layout

//------ PRIVATE FUNCTION ------
