#pragma once

// COLORS
#define COLOR_BLACK       ((SDL_Color){0, 0, 0, 255})
#define COLOR_WHITE       ((SDL_Color){255, 255, 255, 255})
#define COLOR_RED         ((SDL_Color){255, 0, 0, 255})
#define COLOR_GREEN       ((SDL_Color){0, 255, 0, 255})
#define COLOR_BLUE        ((SDL_Color){0, 0, 255, 255})
#define COLOR_YELLOW      ((SDL_Color){255, 255, 0, 255})
#define COLOR_CYAN        ((SDL_Color){0, 255, 255, 255})
#define COLOR_MAGENTA     ((SDL_Color){255, 0, 255, 255})
#define COLOR_ORANGE      ((SDL_Color){255, 165, 0, 255})
#define COLOR_PURPLE      ((SDL_Color){128, 0, 128, 255})
#define COLOR_PINK        ((SDL_Color){255, 192, 203, 255})
#define COLOR_BROWN       ((SDL_Color){139, 69, 19, 255})
#define COLOR_GRAY        ((SDL_Color){128, 128, 128, 255})
#define COLOR_LIGHT_GRAY  ((SDL_Color){211, 211, 211, 255})
#define COLOR_DARK_GRAY   ((SDL_Color){64, 64, 64, 255})
#define COLOR_TRANSPARENT ((SDL_Color){0, 0, 0, 0})

// SETTINGS
// Widget Settings Flags shift (WSF)
#define WSF_NONE_SHIFT              0
#define WSF_ROUND_CORNERS_SHIFT     1
#define WSF_TRANSPARENT_SHIFT       2
#define WSF_ANIMATED_SHIFT          3
#define WSF_INTERACTABLE_SHIFT      4
#define WSF_SHADER_TEXT_SHIFT       5
#define WSF_SHADER_TEXTURE_SHIFT    6

// layout Settings Flags shift (LSF)
#define LSF_NONESHIFT               0

// GUI_SIZE
#define GUI_SIZE_TINY_COEFF     0.25
#define GUI_SIZE_SMALL_COEFF    0.5
#define GUI_SIZE_NORMAL_COEFF   1
#define GUI_SIZE_BIG_COEFF      1.5
#define GUI_SIZE_HUGE_COEFF     1.75
