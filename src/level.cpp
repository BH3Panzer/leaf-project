#include "../header/level.hpp"
#include "../header/growingPlant.hpp"
#include "../header/player.hpp"
#include <iostream>

Level::Level(){}

void Level::addPlatform(Platform plat)
{
    this->platforms.push_back(plat);
    return;
}

void Level::addPlant(GrowingPlant plant) {
    this->plants.push_back(plant);
}

void Level::addManaBloc(ManaBloc mBloc) {
    this->manaBlocs.push_back(mBloc);
}

void Level::drawLevel()
{
    for (Platform plat : this->platforms)
    {
        if (!plat.isPlant())
        {
            plat.drawPlatform();
        }
    }

    for (GrowingPlant plant : this->plants) {
        plant.draw(this->growingVineVertical, this->growingVineFLeftHorizontal, this->growingVineFRightHorizontal);
    }

    for (ManaBloc mBloc : this->manaBlocs) {
        mBloc.draw(this->manaBloc, this->getManaBloc, this->reloadManaBloc, this->reconstitutionManaBloc);
    }

    if (this->id == 1) {
        DrawText("Move with [WASD] or [ZQSD]", 60 - this->cam->x, 200 - this->cam->y, 24, ccolors.black);
        DrawText("Jump with [SPACE]", 52*16 - this->cam->x, 200 - this->cam->y, 24, ccolors.black);
        DrawText("This is a mana block, go on it to take mana, it will rechage", 65*16 - this->cam->x, 55 - this->cam->y, 24, ccolors.black);
        DrawText("Your maximum mana capacity is 20", 120*16 - this->cam->x, 200 - this->cam->y, 24, ccolors.black);
        DrawText("The bar in top left corner represent your mana", 170*16 - this->cam->x, 200 - this->cam->y, 24, ccolors.black);
        DrawText("This door ends the level", 305*16 - this->cam->x, -16 - this->cam->y, 24, ccolors.black);
    }

    DrawTexture(*this->endLevel, this->end.x - this->cam->x, this->end.y - this->cam->y, WHITE);
    //DrawRectangle(this->end.x - this->cam->x, this->end.y - this->cam->y, this->end.width, this->end.height, ccolors.red);
    return;
}

std::vector<Platform> Level::getPlatforms()
{
    return this->platforms;
}

std::vector<GrowingPlant> Level::getPlants() {
    return this->plants;
}

std::vector<ManaBloc> Level::getManaBlocs() {
    return this->manaBlocs;
}


Level::Level(Player* p, Cameraz* cam, Texture2D* gVV, Texture2D* gVFLH, Texture2D* gVFRH, Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB, Texture2D* texturesPlateformes, Texture2D* endLevel, int id) : 
    p(p), cam(cam), growingVineVertical(gVV), growingVineFLeftHorizontal(gVFLH), growingVineFRightHorizontal(gVFRH), manaBloc(MB), getManaBloc(GMB),
    reloadManaBloc(RLMB), reconstitutionManaBloc(RCMB), texturesPlateformes(texturesPlateformes), endLevel(endLevel), id(id)

{
}

Level createLevel(int numLevel, Cameraz* cam, Player* p, float* delta, Texture2D* gVV, Texture2D* gVFLH, Texture2D* gVFRH, Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB, Texture2D* texturesPlateformes, Texture2D* endLevel)
{

    Level level(p, cam, gVV, gVFLH, gVFRH, MB, GMB, RLMB, RCMB, texturesPlateformes, endLevel, numLevel);

    level.unfinish();

    if (numLevel == 1)
    {
        Platform ground({0, static_cast<float>(GetScreenHeight()/1.5), 120, 20}, ccolors.brown, cam, texturesPlateformes);
        Platform beginWall({-48, 0, 1, 20}, ccolors.brown, cam, texturesPlateformes);
        Platform isle1({64*16, 250, 3, 1}, ccolors.brown, cam, texturesPlateformes);
        Platform isle2({72*16, 150, 3, 1}, ccolors.brown, cam, texturesPlateformes);
        Platform isle3({275*16, 75, 2, 1}, ccolors.brown, cam, texturesPlateformes);

        ManaBloc tutoFirstMana(isle2.getRectangle().x + 3*16, isle2.getRectangle().y - 3*16, 5, 10, cam, delta);

        GrowingPlant vine1({isle3.getRectangle().x-1*16*cam->scale, ground.getRectangle().y, (float)16*cam->scale, 0}, 6, false, false, 1, cam, delta);
        GrowingPlant roots1({isle3.getRectangle().x, isle3.getRectangle().y, 0, (float)16*cam->scale}, 7, true, false, 2, cam, delta);

        level.addPlatform(ground);
        level.addPlatform(beginWall);
        level.addPlatform(isle1);
        level.addPlatform(isle2);
        level.addPlatform(isle3);

        level.addManaBloc(tutoFirstMana);

        level.addPlant(vine1);
        level.addPlant(roots1);

        level.setFinishRect({321*16, 75 - 96, 96, 96});

    }
    else if (numLevel == 2) {
        Platform ground({0, static_cast<float>(GetScreenHeight()/1.5), 120, 20}, ccolors.brown, cam, texturesPlateformes);
        Platform isle1({150, 200, 10, 5}, ccolors.brown, cam, texturesPlateformes);

        level.addPlatform(ground);
        level.addPlatform(isle1);
        level.setFinishRect({3000, ground.getRectangle().y - 96, 96, 96});

    }

    return level;
}

GrowingPlant* Level::detectPlant() {
    for (GrowingPlant& plant : this->plants)
    {
        if (plant.isAround(this->p))
        {
            return &plant;
        }

        std::cout << "rect: " << plant.getRect().y << std::endl;
        std::cout << "height: " << plant.getRect().height << std::endl;
    }
    return NULL;
}

ManaBloc* Level::detectManaBloc()
{
    for (ManaBloc& mBloc : this->manaBlocs)
    {
        if (mBloc.isTouch(this->p))
        {
            return &mBloc;
        }
    }
    return NULL;
}

void Level::actualisatePlant()
{
    for (GrowingPlant& plant : this->plants)
    {
        plant.growPlant();
        if (plant.isStateChange())
        {
            if (plant.getId() == -1)
            {
                plant.setId(this->plants.size()+1);
                Platform plat{plant.getRect(true), {WHITE}, this->cam, this->texturesPlateformes, true};
                this->addPlatform(plat);
            }
            else
            {
                this->platforms[plant.getId()].setRectangle(plant.getRect(true));
            }
        }
    }
    return;
}

void Level::actualisateManaBlocs()
{
    for (ManaBloc& mBloc : this->manaBlocs)
    {
        mBloc.actualisate();
    }
}

Texture2D* Level::getSprite(int n)
{
    if (n == 0)
    {
        return this->growingVineVertical;
    }
    else if (n == 1)
    {
        return this->growingVineFLeftHorizontal;
    }
    else if (n == 2)
    {
        return this->growingVineFRightHorizontal;
    }
    return NULL;
}

bool Level::isFinished() {
    return this->finished;
}

void Level::finish() {
    this->finished = true;
}

void Level::unfinish() {
    this->finished = false;
}

Rectangle Level::getFinishRect() {
    return this->end;
}

void Level::setFinishRect(Rectangle rect) {
    this->end = rect;
}

void Level::checkLevelFinished() {
    if (CheckCollisionRecs(this->p->getRect(), this->end)) {
        this->finished = true;
    }
}


