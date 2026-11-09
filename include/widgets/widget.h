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

typedef union WidgetElement {
	Button *button; // TODO: create and add other elements
} WidgetElement;

typedef struct Widget {
	WidgetElement *element;
	WidgetType *type;
} Widget;

Widget *createWidget(WidgetType type, WidgetSettings *settings, GuiContext *gui_context);
int destroyWidget(Widget *widget);
