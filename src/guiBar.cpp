#include "../header/guiBar.hpp"

Bar::Bar(int max, int current, Color col, Color borderCol, Rectangle rect, Cameraz &cam) {
    this->max = max;
    this->current = current;
    this->col = col;
    this->borderCol = borderCol;
    this->rect = rect;
    this->cam = cam;
}

int Bar::getMax() {
    return this->max;
}

int Bar::getCurrent() {
    return this->current;
}

Color Bar::getColor() {
    return this->col;
}

Color Bar::getBorderColor() {
    return this->borderCol;
}

Rectangle Bar::getRectangle() {
    return this->rect;
}

void Bar::setMax(int max) {
    this->max = max;
}

void Bar::setCurrent(int current) {
    this->current = current;
}

void Bar::draw() {
    DrawRectangle(this->rect.x*this->cam.scale, this->rect.y*this->cam.scale, this->rect.width*this->cam.scale, this->rect.height*this->cam.scale, this->borderCol);
    DrawRectangle(this->rect.x*this->cam.scale + 1*this->cam.scale, this->rect.y*this->cam.scale + 1*this->cam.scale, this->current*this->rect.width/this->max*this->cam.scale - 2*this->cam.scale, this->rect.height*this->cam.scale - 2*this->cam.scale, this->col);
}
