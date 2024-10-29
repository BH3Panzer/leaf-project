#include "../header/level.hpp"

void Level::addPlatform(Platform plat)
{
    this->platforms.push_back(plat);
    return;
}

void Level::drawLevel()
{
    for (Platform plat : this->platforms)
    {
        plat.drawPlatform();
    }
    return;
}

std::vector<Platform> Level::getPlatforms()
{
    return this->platforms;
}

Level level1;
struct Ccolors ccolors;

void createLevels(Cameraz &cam)
{
    Platform ground({0, static_cast<float>(GetScreenHeight()/1.5), 8000, 300}, ccolors.brown, cam);
    level1.addPlatform(ground);
    level1.addPlatform({{1000, 0, 30, 1000}, ccolors.brown, cam});
    return;
}