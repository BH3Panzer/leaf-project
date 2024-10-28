#include "../header/level.hpp"
#include "../header/platform.hpp"
#include "../header/colors.hpp"
#include "../header/camera.hpp"

void Level::addPlatform(Platform plat) {
    this-> platformes.push_back(plat);
    return;
}

void Level::drawLevel() {
    for (Platform plat : this->platformes) {
        plat.drawPlatform();
    }
    return;
}

Level level1;
struct Ccolors ccolors;

void createLevels(Cameraz &cam) {
    Platform ground({0, static_cast<float>(GetScreenHeight()/46), 8000, 300}, ccolors.brown, cam);
    level1.addPlatform(ground);
}
