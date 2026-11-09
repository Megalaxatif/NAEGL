#pragma once

#include "settings.h"

typedef struct Rectangle {
	size_t absolute_x;	// in pixels
	size_t absolute_y;
	size_t absolute_w;
	size_t absolute_h;

	double x;			// in percents, between 0. and 1.
	double y;
	double w;
	double h;

	RectangleSettings *settings;
} Rectangle;
