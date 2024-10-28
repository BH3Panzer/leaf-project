#include "../header/level.hpp"

void Level::addPlatform(Platform plat)
{
    this->platformes.push_back(plat);
    return;
}

void Level::drawLevel()
{
    for (Platform plat : this->platformes)
    {
        plat.drawPlatform();
    }
    return;
}

Level level1;

void createLevels(Cameraz &cam)
{
    Platform ground({0, static_cast<float>(GetScreenHeight()/44), 8000, 300}, ccolors.brown, cam);
    Platform test({5, 4, 1, 1}, ccolors.red, cam);
    level1.addPlatform(ground);
    level1.addPlatform(test);
    return;
}
