#include "../header/player.hpp"
#include "../raylib/raylib.h"
#include <cstdlib>
#include <iostream>

Player::Player(Cameraz &cam, float* delta): cam(cam), delta(delta)
{
}

int Player::detectCollision(std::vector<Platform>& platforms, bool horizontal) const
{
    /* fonction qui détecte si un joueur va entrer en collision avec une platform lors d'un déplacement, note: horizontal indique si il s'agit d'un déplacement horizontal */
    int idPlatform{-1};
	int max{-1};
	int i{0};

    float vel{this->vel.x};
    Rectangle rectPlayer{this->rect};
    if (!horizontal)
    {
        vel = this->vel.y;
        rectPlayer.x = this->rect.y;
        rectPlayer.y = this->rect.x;
        rectPlayer.width = this->rect.height;
        rectPlayer.height = this->rect.width;
    }

	if (vel != 0)
	{
		for (auto& platform : platforms)
		{
            const Rectangle pRect{platform.getRectangle()};
			int pX{};
			int pY{};
			int pWidth{};
			int pHeight{};
			if (horizontal)
			{
				pX = pRect.x;
				pY = pRect.y;
				pWidth = pRect.width;
				pHeight = pRect.height;
			}
			else
			{
                pX = pRect.y;
				pY = pRect.x;
				pWidth = pRect.height;
				pHeight = pRect.width;
			}

			if (rectPlayer.y < (pY + pHeight) && (rectPlayer.y + rectPlayer.height) > pY)
			{
				if (vel < 0)
				{
					if ((rectPlayer.x + vel * *this->delta) <= (pX + pWidth) && rectPlayer.x >= (pX + pWidth) && ((pX + pWidth) > max || max == -1))
					{
						max = (pX + pWidth);
						idPlatform = i;
					}
				}
				else
				{
					if ((rectPlayer.x + rectPlayer.width + vel * *this->delta) >= pX && (rectPlayer.x + rectPlayer.width) <= pX && ((pX + pWidth) < max || max == -1))
					{
						max = pX;
						idPlatform = i;
					}
				}
			}
			++i;
		}
	}

	return idPlatform;
}

bool Player::isOnFloor(std::vector<Platform>& platforms)
{
	for (auto& platform : platforms)
	{
        const Rectangle pRect{platform.getRectangle()};
		if ((int)(this->rect.y + this->rect.height + 1) == pRect.y && this->rect.x < (pRect.x + pRect.width) && (this->rect.x + this->rect.width) > pRect.x)
		{
			return true;
		}
	}
	return false;
}

void Player::movement(std::vector<Platform> platforms)
{
    const bool isOnFloor = this->isOnFloor(platforms);

    if (IsKeyDown(KEY_A))
    {
        this->vel.x -= *this->delta * this->acceleration.x;
        if (this->vel.x < -this->velMax.x)
        {
            this->vel.x = -this->velMax.x;
        }
    }
    else if (this->vel.x < 0)
    {
        this->vel.x += (*this->delta) * this->acceleration.x;
        if (this->vel.x > 0)
        {
            this->vel.x = 0;
        }
    }

    if (IsKeyDown(KEY_D))
    {
        this->vel.x += *this->delta * this->acceleration.x;
        if (this->vel.x > this->velMax.x)
        {
            this->vel.x = this->velMax.x;
        }
    }
    else if (this->vel.x > 0)
    {
        this->vel.x -= (*this->delta) * this->acceleration.x;
        if (this->vel.x < 0)
        {
            this->vel.x = 0;
        }
    }

    if (this->vel.x != 0)
    {
        const int idCollision{this->detectCollision(platforms)};

        if (idCollision == -1)
        {
            this->rect.x += this->vel.x * *this->delta;
        }
        else
        {
            const Rectangle pRect{platforms[idCollision].getRectangle()};
            if (this->vel.x < 0)
            {
                this->rect.x = pRect.x + pRect.width;
            }
            else
            {
                this->rect.x = pRect.x - this->rect.width;
            }
            this->vel.x = 0;
        }
    }


    if (isOnFloor)
    {
        if (IsKeyDown(KEY_SPACE))
        {
            this->vel.y = -this->jump;
        }
    }
    else
    {
        const int idCollision{this->detectCollision(platforms, false)};

        if (idCollision == -1)
        {
            this->rect.y += this->vel.y * *this->delta;
            this->vel.y += *this->delta * this->acceleration.y;
        }
        else
        {
            const Rectangle pRect{platforms[idCollision].getRectangle()};
            if (this->vel.y < 0)
            {
                this->rect.y = pRect.y + pRect.height;
            }
            else
            {
                this->rect.y = pRect.y - this->rect.height;
            }
            this->vel.y = 0;
        }
    }

    return;
}

void Player::drawPlayer()
{
    DrawRectangle(this->rect.x - this->cam.x, this->rect.y - this->cam.y, this->rect.width, this->rect.height, RED);
    return;
}

int Player::getMana() {
    return this->mana;
}

void Player::setMana(int mana) {
    if (mana >= 20) {
        this->mana = 20;
    }
    else if (mana <= 0) {
        this->mana = 0;
    }
    else {
        this->mana = mana;
    }
}

void Player::addMana(int q) {
    if (this->mana + q >= 20) {
        this->mana = 20;
    }
    else {
        this->mana+=q;
    }
}

void Player::subMana(int q) {
    if (this->mana - q <= 0) {
        this->mana = 0;
    }
    else {
        this->mana-=q;
    }
}

void Player::manaDebugTest() {
    if (IsKeyPressed(KEY_EIGHT)) {
        this->addMana(1);
        std::cout << this->mana << std::endl;

    }
    else if (IsKeyPressed(KEY_TWO)) {
        this->subMana(2);
        std::cout << this->mana << std::endl;

    }
}

