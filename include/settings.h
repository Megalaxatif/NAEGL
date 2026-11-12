#pragma once

#include "gui_context.h"
#include "shapes/rectangle.h"
#include "widgets/widget.h"

// ------------------- STATE ------------------

typedef enum State {
    STATE_RELEASED = 0,
    STATE_HOVERED,
    STATE_PRESSED,
    STATE_DISABLED,

    STATE_COUNT
} State;

//-------------------- GUI --------------------

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
    GUI_SIZE_NORMAL,
    GUI_SIZE_BIG,
    GUI_SIZE_HUGE
} GuiSize;

typedef struct GuiContextSettings {
    LayoutSettings *layout_settings;
    GuiTheme general_theme;
    GuiSize size;
} GuiContextSettings;


//-------------------- Layout --------------------

typedef enum LayoutDisplayOption {
    LDO_ON, // the layout displays every widgets
    LDO_OFF, // the layout doesn't display any widget
    LDO_FREE // the layout lets the widget decide if it is displayed or not
} LayoutDisplayOption;

typedef enum LayoutSettingsFlags {
    LSF_DEFAULT = 0,
    LSF_NONE = 1 << LSF_NONESHIFT,
    LSF_ORIENTATION_VERTICAL = 1 << LSF_VERTICAL_SHIFT,
    LSF_ORIENTATION_HORIZONTAL =  0 << LSF_HORIZONTAL_SHIFT,
} LayoutSettingsFlags;

typedef struct LayoutSettings{
    ButtonSettings* default_button_settings; // default settings for the button
    // TextBoxSettings* default_textbox_settings; // default settings for the text box
    // SliderSettings* default_slider_settings; // default settings for the slider
    int layout_padding; // padding between the Widgets in the layout
    int layout_originX; // x coordinate of the origin of the layout
    int layout_originY; // y coordinate of the origin of the layout
    LayoutDisplayOption display_option; // ON, OFF or FREE
    ssize_t flags;
    GuiContext *gui_context;
} LayoutSettings;

//-------------------- Widget --------------------

typedef enum WidgetSettingsFlag {   // WSF_ for Widget Settings Flag
    WSF_DEFAULT = 0,                // TODO: apply wanted parameters
    WSF_NONE = 1 << WSF_NONE_SHIFT,
    WSF_ROUND_CORNERS = 1 << WSF_ROUND_CORNERS_SHIFT,
    WSF_TRANSPARENT = 1 << WSF_TRANSPARENT_SHIFT,
    WSF_ANIMATED = 1 << WSF_ANIMATED_SHIFT,
    WSF_INTERACTABLE = 1 << WSF_INTERACTABLE_SHIFT,
    WSF_SHADER_TEXT = 1 << WSF_SHADER_TEXT_SHIFT,
    WSF_SHADER_TEXTURE = 1 << WSF_SHADER_TEXTURE_SHIFT,
    WSF_SHOWN = 1 << WSF_SHOWN_SHIFT

} WidgetSettingsFlag;

typedef union WidgetSettings { // TODO: Create and add other widget settings
    ButtonSettings *buttonSettings;
    //TextBoxSettings *textBoxSettings;
    //SliderSettings *sliderSettings;
} WidgetSettings;


//-------------------- Button --------------------

typedef struct ButtonSettings {
    Rectangle *rect[STATE_COUNT];
    Text *text[STATE_COUNT];
    SDL_Texture *texture[STATE_COUNT];      // Is a mix of the textures from rect and text (raw without shader)
    void (*StateFunction)(void *args)[STATE_COUNT];
    ssize_t flags;
    Layout *layout;
    // TODO link a shader
} ButtonSettings;


//-------------------- Shapes --------------------

typedef struct RectangleSettings {
    SDL_Color border_color;
    SDL_Texture *texture;
    double corner_radius;	// 0. <= value <= 1.
    double border_width;	// 0. <= value <= 1.
    ssize_t flags;
    Layout *layout;
} RectangleSettings;

//-------------------- Text --------------------

typedef struct TextSettings {
    SDL_Font *font;
    SDL_Color color;
    SDL_Texture *texture;
    double padding_x;	// 0. <= value <= 1.
    double padding_y;	// 0. <= value <= 1.
    ssize_t flags;
    Layout *layout;
} TextSettings;


//-------------------- Functions --------------------

GuiContextSettings *CreateGuiContextSettings(ssize_t flags);
int DestroyGuiContextSettings(GuiContextSettings *settings);

LayoutSettings *CreateLayoutSettings(GuiContext *context, ssize_t flags); // create settings based on the default settings of the given gui context, gui context set to NULL will create default settings
int DestroyLayoutSettings(LayoutSettings *settings);

RectangleSettings *CreateRectangleSettings(double w, double h, Layout *layout, ssize_t flags); // create settings based on the default settings of the given layout, layout set to NULL will create default settings
int DestroyRectangleSettings(RectangleSettings *settings);

TextSettings *CreateTextSettings(Layout *layout, ssize_t flags); // create settings based on the default settings of the given layout, layout set to NULL will create default settings
int DestroyTextSettings(TextSettings *settings);

ButtonSettings *CreateButtonSettings(Layout *layout, ssize_t flags); // create settings based on the default settings of the given layout, layout set to NULL will create default settings
int DestroyButtonSettings(ButtonSettings *settings);

WidgetSettings *CreateWidgetSettings(Rectangle *rect, WidgetType type, Layout *layout, ssize_t flags); // create settings based on the default settings of the given layout, layout set to NULL will create default settings
int DestroyWidgetSettings(WidgetSettings *settings);
