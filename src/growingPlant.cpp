#include "../header/growingPlant.hpp"
#include "../header/colors.hpp"
#include "../header/camera.hpp"
#include "../header/player.hpp"
#include <iostream>
GrowingPlant::GrowingPlant(Rectangle rect, int maxSize, bool horizontal, bool fromLeft, int requiredMana, Cameraz* cam, float* delta): rect(rect), maxSize(maxSize), horizontal(horizontal),
    fromLeft(fromLeft), requiredMana(requiredMana), cam(cam), delta(delta)
{
}

Rectangle GrowingPlant::getRect(bool stateOk) {
    if (stateOk)
    {
        this->stateChange = false;
    }
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

void GrowingPlant::growPlant()
{
    if (this->growing && !this->haveGrow)
    {
        this->framePeriod -= *this->delta;
        while (this->framePeriod < 0)
        {
            this->frame++;
            this->framePeriod += 0.0225;
            if (this->frame == 17)
            {
                this->frame = 0;
                this->framePeriod += 0.0225;
                this->size++;
                if (this->size == this->maxSize)
                {
                    this->haveGrow = true;
                    break;
                }
                if (this->horizontal)
                {
                    if (this->fromLeft)
                    {
                        this->rect.width += 32 * this->cam->scale;
                        this->stateChange = true;
                    }
                    else
                    {
                        this->rect.x -= 32 * this->cam->scale;
                        this->rect.width += 32 * this->cam->scale;
                        this->stateChange = true;
                    }
                }
                else
                {
                    this->rect.height += 32 * this->cam->scale;
                    this->rect.y -= 32 * this->cam->scale;
                }
            }
        }
    }
}

void GrowingPlant::startGrowing()
{
    this->growing = true;
    if (this->horizontal)
    {
        if (this->fromLeft)
        {
            this->rect.width += 32 * this->cam->scale;
        }
        else
        {
            this->rect.x -= 32 * this->cam->scale;
            this->rect.width += 32 * this->cam->scale;
        }
        this->stateChange = true;
    }
    else
    {
        this->rect.height += 32 * this->cam->scale;
        this->rect.y -= 32 * this->cam->scale;
    }
}

bool GrowingPlant::isAround(Player* p)
{
    //std::cout << this->rect.x << " " << this->rect.y << " " << this->rect.width << " " << this->rect.height << std::endl;
    if (this->growing)
    {
        return false;
    }
    return (p->getRect().x + p->getRect().width - this->rect.x > -5 && this->rect.x + this->rect.width - p->getRect().x > -5 && p->getMana() >= this->requiredMana && this->rect.height != this->maxSize && this->rect.width != this->maxSize);
}

void GrowingPlant::draw(Texture2D*gVV, Texture2D* gVFLH, Texture2D* gVFRH)
{
    if (!this->haveGrow)
    {
        if (this->growing)
        {
            if (this->horizontal)
            {
                if (this->fromLeft)
                {
                    DrawTextureRec(*gVFLH, {(float)(32 * (16 - this->frame) * this->cam->scale), 0, (float)(32 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x + 32 * this->size * this->cam->scale - this->cam->x, this->rect.y - this->cam->y}, WHITE);
                }
                else
                {
                    DrawTextureRec(*gVFRH, {(float)(32 * this->frame * this->cam->scale), 0, (float)(32 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x - this->cam->x, this->rect.y - this->cam->y}, WHITE);
                }
            }
            else
            {
                DrawTextureRec(*gVV, {0, (float)(32 * this->frame * this->cam->scale), (float)(16 * this->cam->scale), (float)(32 * this->cam->scale)}, {this->rect.x - this->cam->x, this->rect.y - this->cam->y}, WHITE);
            }
        }
        else
        {
            if (this->horizontal)
            {
                if (this->fromLeft)
                {
                    DrawTextureRec(*gVFLH, {(float)(512 * this->cam->scale), 0, (float)(32 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x - this->cam->x, this->rect.y - this->cam->y}, WHITE);
                }
                else
                {
                    DrawTextureRec(*gVFRH, {0, 0, (float)(32 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x - 32 * this->cam->scale - this->cam->x, this->rect.y - this->cam->y}, WHITE);
                }
            }
            else
            {
                DrawTextureRec(*gVV, {0, 0, (float)(16 * this->cam->scale), (float)(32 * this->cam->scale)}, {this->rect.x - this->cam->x, this->rect.y - 32 * this->cam->scale - this->cam->y}, WHITE);
            }
        }
    }
    for (int i = 0; i < size; ++i)
    {
        int ni = i;
        if (!this->haveGrow) ni++;
        if (this->horizontal)
        {
            if (this->fromLeft)
            {
                DrawTextureRec(*gVFLH, {0, 0, (float)(32 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x + 32 * i * this->cam->scale - this->cam->x, this->rect.y - this->cam->y}, WHITE);
            }
            else
            {
                DrawTextureRec(*gVFRH, {gVFRH->width - (float)(32 * this->cam->scale), 0, (float)(32 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->rect.x + 32 * ni * this->cam->scale - this->cam->x, this->rect.y - this->cam->y}, WHITE);
            }
        }
        else
        {
            DrawTextureRec(*gVV, {0, (float)(544 * this->cam->scale), (float)(16 * this->cam->scale), (float)(32 * this->cam->scale)}, {this->rect.x - this->cam->x, this->rect.y + 32 * ni * this->cam->scale - this->cam->y}, WHITE);
        }
    }
}

bool GrowingPlant::isGrowing()
{
    return this->growing;
}

int GrowingPlant::getId()
{
    return id;
}

void GrowingPlant::setId(int n)
{
    this->id = n;
}

bool GrowingPlant::isStateChange()
{
    return this->stateChange;
}