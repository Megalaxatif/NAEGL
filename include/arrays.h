#pragme once

typedef struct LayoutArray {
    size_t capacity;
    size_t count;
    Layout **layouts;
} LayoutArray;

typedef struct WidgetArray {
    size_t capacity;
    size_t count;
    Widget **widgets;
} WidgetArray;
