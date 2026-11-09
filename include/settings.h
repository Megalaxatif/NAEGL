#pragma once

#include "gui_context.h"
#include "shapes/rectangle.h"
#include "widgets/widget.h"

typedef enum State {
    STATE_IDLE = 0,
    STATE_HOVER,
    STATE_PRESSED,
    STATE_DISABLED,

    STATE_COUNT
} MouseState;

// Layout
typedef struct LayoutSettings {
    size_t nb_element;
    int on_grid;
    WidgetType *type;
} LayoutSettings;

typedef struct LayoutSettingsArray {
    size_t capacity;
    size_t count;
    LayoutSettings **settings;
} LayoutSettingsArray;

// GuiContext
typedef enum GuiTheme {
    GUI_THEME_NONE,
    GUI_THEME_DARK,
    GUI_THEME_LIGHT,
    GUI_THEME_CUSTOM
} GuiTheme;

typedef enum GuiSize {	// Multiplicator
    GUI_SIZE_TINY,
    GUI_SIZE_SMALL,
    GUI_SIZE_NORMAL,	// Should be times 1
    GUI_SIZE_BIG,
    GUI_SIZE_HUGE
} GuiSize;

typedef struct GuiContextSettings {
    GuiTheme general_theme;
    GuiSize size;
} GuiContextSettings;

// Shapes
typedef struct RectangleSettings {
    SDL_Color border_color;
    SDL_Texture *texture;
    double corner_radius;	// 0. <= value <= 1.
    double border_width;	// 0. <= value <= 1.
    GuiContext *gui_context;
} RectangleSettings;

typedef struct TextSettings {
    SDL_Font *font;
    SDL_Color color;
    SDL_Texture *texture;
    double padding_x;	// 0. <= value <= 1.
    double padding_y;	// 0. <= value <= 1.
    GuiContext *gui_context;
} TextSettings;

// Widgets
typedef struct ButtonSettings { 
    Rectangle *rect[STATE_COUNT];
    Text *text[STATE_COUNT];
    SDL_Texture *texture[STATE_COUNT];		// Is a mix of the textures from rect and text (raw without shader)
    void (*StateFunction)(void *args)[STATE_COUNT];
    ssize_t flags;
    GuiContext *gui_context;
    // TODO link a shader
} ButtonSettings;

typedef enum WidgetSettingsFlag {	// WSF_ for Widget Settings Flag
    WSF_DEFAULT = 0,				// TODO: apply wanted parameters
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

typedef struct WidgetSettingsArray {
    size_t capacity;
    size_t count;
    WidgetSettings **settings;
    WidgetType *type;
} WidgetSettingsArray;

// Functions
GuiContextSettings *createGuiContextSettings(ssize_t flags);
int destroyGuiContextSettings(GuiContextSettings *gui_context);

RectangleSettings *createRectangleSettings(ssize_t flags, GuiContext *gui_context);
RectangleSettings *createDefaultRectangleSettings(double w, double h, GuiContext *gui_context);
int destroyRectangleSettings(RectangleSettings *settings);

TextSettings *createTextSettings(ssize_t flags, GuiContext *gui_context);
int destroyTextSettings(TextSettings *settings);

ButtonSettings *createButtonSettings(ssize_t flags, GuiContext *gui_context);
int destroyButtonSettings(ButtonSettings *settings);

WidgetSettings *createWidgetSettings(Rectangle *rect, WidgetType type, GuiContext *gui_context, ssize_t flags);
int destroyWidgetSettings(WidgetSettings *settings);
