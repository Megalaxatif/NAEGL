#pragma once

#include "settings.h"
#include "layout.h"

typedef struct Rectangle {
    int pixel_coord_x;	// in pixels
    int pixel_coord_y;
    int pixel_coord_w;
    int pixel_coord_h;

    double normalized_coord_x;			// in percents, between 0. and 1.
    double normalized_coord_y;
    double normalized_coord_w;
    double normalized_coord_h;

    Layout *layout;

    RectangleSettings *settings;
} Rectangle;

Rectangle *CreateRectangle(double x, double y, double w, double h, Layout *layout, ssize_t flags);
int DestroyRectangle(Rectangle *rectangle);
