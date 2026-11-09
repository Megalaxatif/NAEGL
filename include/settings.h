#pragma once

#include "shapes/rectangle.h"
#include "widgets/widget.h"

typedef enum State {
    STATE_IDLE = 0,
    STATE_HOVER,
    STATE_PRESSED,
    STATE_DISABLED,

    STATE_COUNT
} MouseState;

typedef struct RectangleSettings {
    SDL_Color border_color;
    SDL_Texture *texture;
	double corner_radius;	// 0. <= value <= 1.
    double border_width;	// 0. <= value <= 1.
} RectangleSettings;

typedef struct TextSettings {
	SDL_Font *font;
	SDL_Color color;
	SDL_Texture *texture;
	double padding_x;	// 0. <= value <= 1.
	double padding_y;	// 0. <= value <= 1.
} TextSettings;

typedef struct ButtonSettings { 
	Rectangle *rect[STATE_COUNT];
	Text *text[STATE_COUNT];
	SDL_Texture *texture[STATE_COUNT];		// Is a mix of the textures from rect and text (raw without shader)
    void (*StateFunction)(void *args)[STATE_COUNT];
	ssize_t flags;
	// TODO link a shader
} ButtonSettings;

typedef enum WidgetSettingsFlag { // WSF_ for Widget Settings Flag
    WSF_NONE = 1 << WSF_NONE_SHIFT,
    WSF_ROUND_CORNERS = 1 << WSF_ROUND_CORNERS_SHIFT,
    WSF_TRANSPARENT = 1 << WSF_TRANSPARENT_SHIFT,
    WSF_ANIMATED = 1 << WSF_ANIMATED_SHIFT,
    WSF_INTERACTABLE = 1 << WSF_INTERACTABLE_SHIFT,
    WSF_SHADER_TEXT = 1 << WSF_SHADER_TEXT_SHIFT,
    WSF_SHADER_TEXTURE = 1 << WSF_SHADER_TEXTURE_SHIFT
} WidgetSettingsFlag;

typedef union WidgetSettings { // TODO: Create and add other widget settings
	ButtonSettings *buttonSettings;
} WidgetSettings;


// Functions
RectangleSettings *createRectangleSettings(ssize_t flags);
int destroyRectangleSettings(RectangleSettings *settings);

TextSettings *createTextSettings(ssize_t flags);
int destroyTextSettings(TextSettings *settings);

ButtonSettings *createButtonSettings(ssize_t flags);
int destroyButtonSettings(ButtonSettings *settings);

WidgetSettings *createWidgetSettings(Rectangle *rect, WidgetType *Type, ssize_t flags);
int destroyWidgetSettings(WidgetSettings *settings);
