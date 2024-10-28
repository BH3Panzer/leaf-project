#include "../header/platform.hpp"

Platform::Platform(Rectangle rect, Color col, Cameraz &cam)
{
    this->rect = rect;
    this->col = col;
    this->cam = cam;
}

Rectangle Platform::getRectangle()
{
    return this->rect;
}

void Platform::setRectangle(Rectangle rect)
{
    this->rect = rect;
    return;
}

void Platform::drawPlatform()
{
    DrawRectangle(this->rect.x*this->cam.scale - this->cam.x*this->cam.scale, this->rect.y*this->cam.scale - this->cam.y*this->cam.scale, this->rect.width*this->cam.scale, this->rect.height*this->cam.scale, this->col);
    return;
}
