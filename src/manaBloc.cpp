#include "../header/manaBloc.hpp"
#include "../header/camera.hpp"
#include "../header/player.hpp"

ManaBloc::ManaBloc(int x, int y, int quantityOfMana, int reloadDuration, Cameraz* cam, float* delta): x(x), y(y), quantityOfMana(quantityOfMana), reloadDuration(reloadDuration), cam(cam), delta(delta)
{
}

int ManaBloc::getX() {
    return this->x;
}

int ManaBloc::getY() {
    return this->y;
}

void ManaBloc::draw(Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB)
{
    if (this->step == 0)
    {
        DrawTexture(*MB, this->x - this->cam->x, this->y - this->cam->y - this->offset * this->cam->scale, WHITE);
    }
    else
    {
        Texture2D* sprite;
        if (this->step == 1)
        {
            sprite = GMB;
        }
        else if (this->step == 2)
        {
            sprite = RLMB;
        }
        else
        {
            sprite = RCMB;
        }
        DrawTextureRec(*sprite, {0, (float)(16 * this->cam->scale * this->frame), (float)(16 * this->cam->scale), (float)(16 * this->cam->scale)}, {this->x - this->cam->x, this->y - this->cam->y - this->offset * this->cam->scale}, WHITE);
    }
}

bool ManaBloc::isLoad(bool useBloc)
{
    if (useBloc && this->step == 0)
    {
        this->step = 1;
        this->framePeriod = 0.1;
        return true;
    }
    return (this->step == 0);
}

bool ManaBloc::isTouch(Player* p)
{
    Rectangle rectPlayer = p->getRect();
    return (rectPlayer.x <= this->x + 16 * this->cam->scale && rectPlayer.x + rectPlayer.width >= this->x && rectPlayer.y <= this->y + 16 * this->cam->scale && rectPlayer.y + rectPlayer.height >= this->y);
}

void ManaBloc::actualisate()
{
    this->offset -= *this->delta;
    while(this->offset < 0)
    {
        this->offsetPeriod += 0.1;
        if (this->goUp)
        {
            this->offset++;
            if (this->offset == 5)
            {
                this->goUp = false;
            }
        }
        else
        {
            this->offset--;
            if (this->offset == -5)
            {
                this->goUp = true;
            }
        }
    }

    if (this->step != 0)
    {
        this->framePeriod -= *this->delta;
        while(this->framePeriod < 0)
        {
            this->frame++;
            this->framePeriod += 0.1;
            if (this->step == 1 && this->frame == 7)
            {
                this->frame = 0;
                this->step = 2;
            }
            else if (this->frame == 8)
            {
                this->frame = 0;
                if (this->step == 2)
                {
                    this->reloadingStep++;
                    if (this->reloadingStep == this->reloadDuration)
                    {
                        this->step = 3;
                        this->reloadingStep = 0;
                    }
                }
                else
                {
                    this->framePeriod = 0;
                    this->step = 0;
                }
            }
        }
    }
}

int ManaBloc::getQuantityOfMana()
{
    return this->quantityOfMana;
}