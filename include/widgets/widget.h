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
	//Slider *slider;
	//TextBox *textBox;
} WidgetElement;

typedef struct Widget {
	WidgetElement *element;
	WidgetType *type;
	Layout* layout; // the layout the widget belongs to
} Widget;

Widget *createWidget(WidgetType *type, Rectangle* rect, GuiContext* gui_context, ssize_t flags);
int destroyWidget(Widget *widget);
