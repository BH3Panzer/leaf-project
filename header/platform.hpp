#ifndef PLATFORM
#define PLATFORM
#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/camera.hpp"

class Platform {
    private:
    Rectangle rect;
    Color col;
    Cameraz cam;

    public:
    void drawPlatform();
    Rectangle getRectangle();
    void setRectangle(Rectangle rect);
    Platform(Rectangle rect, Color col, Cameraz &cam);
};


#endif
