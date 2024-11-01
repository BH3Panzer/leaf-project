#include "../header/player.hpp"
#include <cstddef>
#include <iostream>

Player::Player(){}

Player::Player(Cameraz* cam, float* delta, Image sprite, Image spriteRun, Image spriteJump, Image spriteConcetration, Image spriteGrow, Image spriteBridge): cam(cam), delta(delta)
{
    this->rect = {5, 5, (float)(12 * cam->scale), (float)(16 * cam->scale)};
    ImageResizeNN(&sprite, (int)(16 * cam->scale), (int)(16 * cam->scale));
    this->sprite.s = LoadTextureFromImage(sprite);
    ImageFlipHorizontal(&sprite);
    this->sprite.rs = LoadTextureFromImage(sprite);

    ImageResizeNN(&spriteRun, (int)(16 * cam->scale), (int)(180 * cam->scale));
    this->spriteRun.s = LoadTextureFromImage(spriteRun);
    ImageFlipHorizontal(&spriteRun);
    this->spriteRun.rs = LoadTextureFromImage(spriteRun);

    ImageResizeNN(&spriteJump, (int)(16 * cam->scale), (int)(54 * cam->scale));
    this->spriteJump.s = LoadTextureFromImage(spriteJump);
    ImageFlipHorizontal(&spriteJump);
    this->spriteJump.rs = LoadTextureFromImage(spriteJump);

    ImageResizeNN(&spriteConcetration, (int)(32 * cam->scale), (int)(480 * cam->scale));
    this->spriteConcetration.s = LoadTextureFromImage(spriteConcetration);
    ImageFlipHorizontal(&spriteConcetration);
    this->spriteConcetration.rs = LoadTextureFromImage(spriteConcetration);

    ImageResizeNN(&spriteGrow, (int)(32 * cam->scale), (int)(288 * cam->scale));
    this->spriteGrow.s = LoadTextureFromImage(spriteGrow);
    ImageFlipHorizontal(&spriteGrow);
    this->spriteGrow.rs = LoadTextureFromImage(spriteGrow);

    ImageResizeNN(&spriteBridge, (int)(32 * cam->scale), (int)(576 * cam->scale));
    this->spriteBridge.s = LoadTextureFromImage(spriteBridge);
    ImageFlipHorizontal(&spriteBridge);
    this->spriteBridge.rs = LoadTextureFromImage(spriteBridge);
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
		if ((int)(this->rect.y + this->rect.height) == pRect.y && this->rect.x < (pRect.x + pRect.width) && (this->rect.x + this->rect.width) > pRect.x)
		{
			return true;
		}
	}
	return false;
}

bool Player::isOnGrowingVine(std::vector<GrowingPlant>& plants)
{
    for (auto& plant : plants)
	{
        if (!plant.isHorizontal())
        {
            Rectangle rectPlant = plant.getRect();
            if (this->rect.x + this->rect.width > rectPlant.x && this->rect.x < rectPlant.x + rectPlant.width && this->rect.y + this->rect.height > rectPlant.y && this->rect.y < rectPlant.y + rectPlant.height)
            {
                return true;
            }
        }
    }
    return false;
}

void Player::movement(std::vector<Platform> platforms, std::vector<GrowingPlant> plants)
{
    const bool isOnFloor = this->isOnFloor(platforms);
    const bool isOnGrowingVine = this->isOnGrowingVine(plants);

    if (!(this->pConcentration && isOnFloor))
    {
        if (this->pConcentration)
        {
            this->plantAround = NULL;
            this->frame = -1;
            this->framePeriod = 0;
            this->pConcentration = false;
        }

        if (IsKeyDown(KEY_A))
        {
            this->vel.x -= *this->delta * this->acceleration.x;
            if (this->vel.x < -this->velMax.x)
            {
                this->vel.x = -this->velMax.x;
            }
            if (this->vel.x < 0 && lookRight)
            {
                lookRight = false;
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
            if (this->vel.x > 0 && !lookRight)
            {
                lookRight = true;
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
                if (isOnFloor)
                {
                    this->framePeriod -= *this->delta;
                    while (this->framePeriod < 0)
                    {
                        this->frame++;
                        this->framePeriod += 0.05;
                        if (this->frame == 10)
                        {
                            this->frame = 0;
                        }
                    }
                }
                else if (this->frame != -1)
                {
                    this->frame = -1;
                    this->framePeriod = 0;
                }
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
                this->frame = -1;
                this->framePeriod = 0;
            }
        }


        if (isOnFloor)
        {
            if (IsKeyDown(KEY_SPACE))
            {
                this->vel.y = -this->jump;
            }
        }
        if (isOnGrowingVine)
        {
            if (IsKeyDown(KEY_W))
            {
                this->vel.y -= *this->delta * this->climbingSpeed;
                if (this->vel.y < -this->climbingMaxSpeed)
                {
                    this->vel.y = -this->climbingMaxSpeed;
                }
            }
        }
        if (!isOnFloor || this->vel.y != 0)
        {
            const int idCollision{this->detectCollision(platforms, false)};

            if (idCollision == -1)
            {
                this->rect.y += this->vel.y * *this->delta;
                if (!(isOnGrowingVine && IsKeyDown(KEY_W)) || this->vel.y < -this->climbingMaxSpeed)
                {
                    this->vel.y += *this->delta * this->acceleration.y;
                }
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
    }

    return;
}

void Player::drawPlayer()
{
    //DrawRectangle(this->rect.x - (*this->cam).x, this->rect.y - (*this->cam).y, this->rect.width, this->rect.height, RED);
    if (!this->pConcentration)
    {
        std::vector<Texture2D*> sprites;
        if (this->lookRight)
        {
            sprites.push_back(&this->sprite.s);
            sprites.push_back(&this->spriteRun.s);
            sprites.push_back(&this->spriteJump.s);
        }
        else
        {
            sprites.push_back(&this->sprite.rs);
            sprites.push_back(&this->spriteRun.rs);
            sprites.push_back(&this->spriteJump.rs);
        }

        if (this->vel.y != 0)
        {
            Rectangle rectAnim{0, 0, (float)(16 * this->cam->scale), (float)(18 * this->cam->scale)};
            if (-150 < this->vel.y && this->vel.y < 150)
            {
                rectAnim.y = (float)(18 * this->cam->scale);
            }
            else if (this->vel.y >= 150)
            {
                rectAnim.y = (float)(36 * this->cam->scale);
            }
            DrawTextureRec(*sprites[2], rectAnim, {this->rect.x - this->cam->x - this->cam->scale * 2, this->rect.y - this->cam->y - this->cam->scale * 2}, WHITE);
        }
        else if (this->vel.x != 0)
        {
            DrawTextureRec(*sprites[1], {0, (float)(18 * this->frame * this->cam->scale), (float)(16 * this->cam->scale), (float)(18 * this->cam->scale)}, {this->rect.x - this->cam->x - this->cam->scale * 2, this->rect.y - this->cam->y - this->cam->scale * 2}, WHITE);
        }
        else
        {
            DrawTexture(*sprites[0], this->rect.x - this->cam->x - this->cam->scale * 2, this->rect.y - this->cam->y, WHITE);
        }
    }
    else
    {
        Texture2D* sprites;
        if (this->pReady)
        {
            if (this->lookRight)
            {
                if (this->plantAround->isHorizontal())
                {
                    sprites = &this->spriteBridge.s;
                }
                else
                {
                    sprites = &this->spriteGrow.s;
                }
            }
            else
            {
                if (this->plantAround->isHorizontal())
                {
                    sprites = &this->spriteBridge.rs;
                }
                else
                {
                    sprites = &this->spriteGrow.rs;
                }
            }
            
        }
        else
        {
            if (this->lookRight)
            {
                sprites = &this->spriteConcetration.s;
            }
            else
            {
                sprites = &this->spriteConcetration.rs;
            }
        }
        DrawTextureRec(*sprites, {0, (float)(32 * this->frame * this->cam->scale), (float)(32 * this->cam->scale), (float)(32 * this->cam->scale)}, {this->rect.x - (*this->cam).x - this->cam->scale * 10, this->rect.y - (*this->cam).y - this->cam->scale * 16}, WHITE);
    }
    return;
}

int Player::getMana() {
    return this->mana;
}

void Player::setMana(unsigned int mana) {
    if (mana >= 20) {
        this->mana = 20;
    }
    else {
        this->mana = mana;
    }
}

void Player::addMana(unsigned int q) {
    this->mana += q;
    if (this->mana > 20) {
        this->mana = 20;
    }
}

void Player::subMana(unsigned int q) {
    this->mana -= q;
    if (this->mana < 0) {
        this->mana = 0;
    }
}


void Player::manaDebugTest() {
    if (IsKeyPressed(KEY_EIGHT)) {
        this->addMana(1);
        std::cout << "mana: " << this->mana << std::endl;

    }
    else if (IsKeyPressed(KEY_TWO)) {
        this->subMana(2);
        std::cout << "mana: " << this->mana << std::endl;

    }
}

Rectangle Player::getRect() {
    return this->rect;
}

Vector2 Player::getVel() {
    return this->vel;
}

Vector2 Player::getVelMax() {
    return this->velMax;
}

void Player::handleInterract(Level* level)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        if (this->vel.x == 0 && this->vel.y == 0)
        {
            this->plantAround = level->detectPlant();
            this->frame = 0;
            this->framePeriod = 0.1;
            this->pConcentration = true;
        }
    }
    else if (this->pConcentration)
    {
        if (this->pReady)
        {
            this->framePeriod -= *this->delta;
            while (this->framePeriod < 0)
            {
                this->frame++;
                this->framePeriod += 0.1;
                const bool isHorizontal{this->plantAround->isHorizontal()};
                if (isHorizontal && this->frame == 13)
                {
                    this->plantAround->startGrowing();
                }
                else if (!isHorizontal && this->frame == 5)
                {
                    this->plantAround->startGrowing();
                }
                else if ((!isHorizontal && this->frame == 8) || this->frame == 17)
                {
                    this->frame = -1;
                    this->framePeriod = 0;
                    this->plantAround = NULL;
                    this->pConcentration = false;
                    this->pReady = false;
                    break;
                }
            }
        }
        else
        {
            if (IsKeyDown(KEY_ENTER))
            {
                this->framePeriod -= *this->delta;
                while (this->framePeriod < 0)
                {
                    this->frame++;
                    this->framePeriod += 0.1;
                    if (this->frame == 15)
                    {
                        this->frame = 0;
                        this->framePeriod = 0.1;
                        if (this->plantAround != NULL)
                        {
                            this->pReady = true;
                            this->subMana(this->plantAround->getRequiredMana());
                        }
                        break;
                    }
                }
            }
            else
            {
                this->plantAround = NULL;
                this->frame = -1;
                this->framePeriod = 0;
                this->pConcentration = false;
            }
        }
    }
}

void Player::recoverManaBloc(Level* level)
{
    ManaBloc* manaBlocRecolted = level->detectManaBloc();

    if (manaBlocRecolted != NULL)
    {
        if (manaBlocRecolted->isLoad(true))
        {
            this->addMana(manaBlocRecolted->getQuantityOfMana());
        }
    }
}