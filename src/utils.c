#include <utils.h>

int isRectangleCollision(Rectangle rectangle, double x, double y){
    return x>=rectangle.x && x <= rectangle.x + rectangle.w && y >= rectangle.y && y <= rectangle.y + rectangle.h;
}
