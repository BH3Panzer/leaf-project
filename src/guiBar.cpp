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
    DrawRectangle(this->rect.x, this->rect.y, this->rect.width, this->rect.height, this->borderCol);
    DrawRectangle(this->rect.x + 5, this->rect.y + 5, this->current*this->rect.width/this->max - 10, this->rect.height - 10, this->col);
}
