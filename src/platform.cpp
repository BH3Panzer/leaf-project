#include "../header/platform.hpp"
#include <iostream>

Platform::Platform(Rectangle rect, Color col, Cameraz* cam, Texture2D* sprite, bool plant)
{
    if (!plant)
    {
        this->width = rect.width;
        this->height = rect.height;
        this->rect = rect;
        this->rect.width *= 16 * cam->scale;
        this->rect.height *= 16 * cam->scale;
    }
    else
    {
        this->rect = rect;
    }
    this->col = col;
    this->cam = cam;
    this->sprite = sprite;
    this->plant = plant;
    for (int i = 0; i < this->width * this-> height; ++i)
    {
        this->texturePattern.push_back(GetRandomValue(0, 9));
    }
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
    for (int x = 0; x < this->width; ++x)
    {
        for (int y = 0; y < this->height; ++y)
        {
            DrawTextureRec(*sprite, {(float)(16 * this->cam->scale * texturePattern[(x * y + x)]), 0, (float)(16 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x + x * 16 * this->cam->scale - this->cam->x, this->rect.y + y * 16 * this->cam->scale - this->cam->y}, WHITE);
        }
    }
    //DrawRectangle(this->rect.x - this->cam->x, this->rect.y - this->cam->y, this->rect.width, this->rect.height, this->col);
    return;
}

bool Platform::isPlant()
{
    return this->plant;
}