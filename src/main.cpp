#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/platform.hpp"
#include "../header/level.hpp"
#include "../header/camera.hpp"
#include "../header/player.hpp"

int main()
{
    InitWindow(1024, 576, "Leaf Project");
    SetTargetFPS(60);
    Ccolors ccolors;
    createLevels(mainCamera);
    float delta{};
    Player player{mainCamera, &delta};
    
    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        player.movement(level1.getPlatforms());
        BeginDrawing();
        ClearBackground(ccolors.blue);
        level1.drawLevel();
        player.drawPlayer();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
