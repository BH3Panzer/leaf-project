#include "../header/platform.hpp"
#include <cstddef>
#include <iostream>
Platform::Platform(Rectangle rect, Color col, Cameraz* cam)
{
    this->rect = rect;
    this->col = col;
    this->cam = cam;
}

Rectangle Platform::getRectangle()
{
    return this->rect;
}

Color Platform::getColor() {
    return this->col;
}

void Platform::setRectangle(Rectangle rect)
{
    this->rect = rect;
    return;
}

void Platform::setColor(Color col) {
    this->col = col;
    return;
}

void Platform::drawPlatform()
{
    DrawRectangle(this->rect.x - this->cam->x, this->rect.y - this->cam->y, this->rect.width, this->rect.height, this->col);
    return;
}

bool Platform::isPlant()
{
    return this->cam == NULL;
}