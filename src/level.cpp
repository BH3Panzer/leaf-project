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
        plat.drawPlatform();
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

Level::Level(Player* p) {
    this->p = p;
}


Level createLevel1(Cameraz* cam, Player* p)
{
    Level level1(p);
    Platform ground({0, static_cast<float>(GetScreenHeight()/1.5), 8000, 300}, ccolors.brown, cam);
    Platform isle1({500, 250, 100, 50}, ccolors.brown, cam);
    Platform isle2({800, 150, 100, 50}, ccolors.brown, cam);
    GrowingPlant test({950, ground.getRectangle().y, 32, 32}, 150, false, 0, cam);

    GrowingPlant test2({isle1.getRectangle().x + isle1.getRectangle().width - 32, isle1.getRectangle().y, 32, 32}, 200, true, 15, cam);
    level1.addPlatform(ground);
    level1.addPlatform(isle1);
    level1.addPlatform(isle2);
    level1.addPlant(test);
    level1.addPlant(test2);

    return level1;
}

void Level::handleInterract() {
    if (IsKeyPressed(KEY_ENTER)) {
        for (GrowingPlant& plant : this->plants) {
            plant.growPlant(this->p);
            std::cout << "rect: " << plant.getRect().y << std::endl;
            std::cout << "height: " << plant.getRect().height << std::endl;
        }
    }
}
