#pragma once

#include "settings.h"
#include "gui_context.h"
#include "widget/button.h"

typedef enum WidgetType {
    WIDGET_TYPE_BUTTON,
    WIDGET_TYPE_SLIDER,
    WIDGET_TYPE_TEXTBOX,
    WIDGET_TYPE_NONE
} WidgetType;

// typedef enum WidgetAlignment {
//     WIDGET_ALIGNMENT_START,
//     WIDGET_ALIGNMENT_CENTER,
//     WIDGET_ALIGNMENT_END,
//     WIDGET_ALIGNMENT_START
// } WidgetType;

typedef union WidgetElement {
    Button *button; // TODO: create and add other elements
    // Slider *slider;
    // TextBox *textBox;
} WidgetElement;

typedef struct Widget {
    WidgetElement *element;
    WidgetType *type;
    Layout* layout; // the layout the widget belongs to
} Widget;

Widget *CreateWidget(WidgetType type, Rectangle *rect, GuiContext *gui_context, ssize_t flags); // Create on default layout
int SetWidgetSettings(Widget* target, WidgetSettings *settings); // COPY the given settings into the settings of the widget target
int SetWidgetHAlignment(Widget* target, WidgetAlignment alignment);
int SetWidgetVAlignment(Widget* target, WidgetAlignment alignment);

int DestroyWidget(Widget *widget);
