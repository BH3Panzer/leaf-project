#include "../header/level.hpp"
#include "../header/growingPlant.hpp"
#include "../header/player.hpp"
#include <iostream>

void Level::addPlatform(Platform plat)
{
    this->platforms.push_back(plat);
    return;
}

void Level::addPlant(GrowingPlant plant) {
    this->plants.push_back(plant);
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
        plant.draw();
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

Level::Level(Player* p, Cameraz* cam, Image growingVine) : p(p), cam(cam)
{
    ImageResizeNN(&growingVine, (int)(16 * this->cam->scale), (int)(576 * this->cam->scale));
    this->growingVineVertical = LoadTextureFromImage(growingVine);
    ImageRotateCW(&growingVine);
    this->growingVineFLeftHorizontal = LoadTextureFromImage(growingVine);
    ImageFlipHorizontal(&growingVine);
    this->growingVineFRightHorizontal = LoadTextureFromImage(growingVine);
}

Level createLevel1(Cameraz* cam, Player* p, float* delta, Image growingVine)
{
    Level level1(p, cam, growingVine);

    Platform ground({0, static_cast<float>(GetScreenHeight()/1.5), 8000, 300}, ccolors.brown, cam);
    Platform isle1({500, 250, 100, 48}, ccolors.brown, cam);
    Platform isle2({800, 150, 100, 48}, ccolors.brown, cam);

    GrowingPlant test({950, ground.getRectangle().y, (float)(16 * cam->scale), 0}, 5, false, 0, cam, delta, level1.getSprite(0));
    GrowingPlant test2({isle1.getRectangle().x + isle1.getRectangle().width, isle1.getRectangle().y, 0, (float)(16 * cam->scale)}, 10, true, 15, cam, delta, level1.getSprite(1));

    level1.addPlatform(ground);
    level1.addPlatform(isle1);
    level1.addPlatform(isle2);
    level1.addPlant(test);
    level1.addPlant(test2);

    return level1;
}

GrowingPlant* Level::detectPlant() {
    for (GrowingPlant& plant : this->plants) {
        if (plant.isAround(this->p))
        {
            return &plant;
        }

        std::cout << "rect: " << plant.getRect().y << std::endl;
        std::cout << "height: " << plant.getRect().height << std::endl;
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

Texture2D* Level::getSprite(int n)
{
    if (n == 0)
    {
        return &this->growingVineVertical;
    }
    else if (n == 1)
    {
        return &this->growingVineFLeftHorizontal;
    }
    else if (n == 2)
    {
        return &this->growingVineFRightHorizontal;
    }
    return NULL;
}
