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

Level::Level(Player* p, Cameraz* cam, Texture2D* gVV, Texture2D* gVFLH, Texture2D* gVFRH, Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB) : p(p), cam(cam),
    growingVineVertical(gVV), growingVineFLeftHorizontal(gVFLH), growingVineFRightHorizontal(gVFRH), manaBloc(MB), getManaBloc(GMB), reloadManaBloc(RLMB), reconstitutionManaBloc(RCMB)
{
}

Level createLevel(int numLevel, Cameraz* cam, Player* p, float* delta, Texture2D* gVV, Texture2D* gVFLH, Texture2D* gVFRH, Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB)
{
    Level level(p, cam, gVV, gVFLH, gVFRH, MB, GMB, RLMB, RCMB);

    if (numLevel == 1)
    {
        Platform ground({0, static_cast<float>(GetScreenHeight()/1.5), 8000, 300}, ccolors.brown, cam);
        Platform isle1({500, 250, 100, 48}, ccolors.brown, cam);
        Platform isle2({800, 150, 100, 48}, ccolors.brown, cam);

        GrowingPlant test({950, ground.getRectangle().y, (float)(16 * cam->scale), 0}, 5, false, false, 0, cam, delta);
        GrowingPlant test2({isle1.getRectangle().x + isle1.getRectangle().width, isle1.getRectangle().y, 0, (float)(16 * cam->scale)}, 10, true, true, 15, cam, delta);

        ManaBloc mbTest(840, 80, 5, 3, cam, delta);
        ManaBloc mbTest2(1040, 300, 50, 10, cam, delta);

        level.addPlatform(ground);
        level.addPlatform(isle1);
        level.addPlatform(isle2);
        level.addPlant(test);
        level.addPlant(test2);
        level.addManaBloc(mbTest);
        level.addManaBloc(mbTest2);
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
                this->addPlatform({plant.getRect(), {}, NULL});
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
