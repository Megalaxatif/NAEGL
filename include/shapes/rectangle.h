#pragma once

#include "settings.h"
#include "layout.h"

typedef struct Rectangle {
    size_t absolute_x;	// in pixels
    size_t absolute_y;
    size_t absolute_w;
    size_t absolute_h;

    double x;			// in percents, between 0. and 1.
    double y;
    double w;
    double h;

    Layout *layout;

    RectangleSettings *settings;
} Rectangle;

Rectangle *CreateRectangle(double x, double y, double w, double h, Layout *layout, ssize_t flags);
int DestroyRectangle(Rectangle *rectangle);
