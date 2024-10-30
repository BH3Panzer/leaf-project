#include "../header/growingPlant.hpp"
#include "../header/colors.hpp"
#include "../header/camera.hpp"
#include "../header/player.hpp"

GrowingPlant::GrowingPlant(Rectangle rect, int maxSize, bool horizontal, int requiredMana, Cameraz* cam) {
    this->rect = rect;
    this->maxSize = maxSize;
    this->horizontal = horizontal;
    this->requiredMana = requiredMana;
    this->cam = cam;
}

Rectangle GrowingPlant::getRect() {
    return this->rect;
}

bool GrowingPlant::isHorizontal() {
    return this->horizontal;
}

int GrowingPlant::getMawSize() {
    return this->maxSize;
}

int GrowingPlant::getRequiredMana() {
    return this->requiredMana;
}

void GrowingPlant::growPlant(Player* p) {
    if (p->getRect().x + p->getRect().width - this->rect.x > -5 && this->rect.x + this->rect.width - p->getRect().x > -5 && p->getMana() >= this->requiredMana && this->rect.height != this->maxSize && this->rect.width != this->maxSize) {
        p->subMana(this->requiredMana);
        if (this->horizontal) {
            this->rect.width = this->maxSize;
        }
        else {
            this->rect.height = this->maxSize;
            this->rect.y -= this->maxSize;
        }
    }
}

void GrowingPlant::draw() {
    DrawRectangle(this->rect.x - this->cam->x, this->rect.y - this->cam->y, this->rect.width, this->rect.height, ccolors.lightGreen);
}
