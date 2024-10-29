#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/platform.hpp"
#include "../header/level.hpp"
#include "../header/camera.hpp"
#include "../header/guiBar.hpp"
#include "../header/player.hpp"


int main()
{
    InitWindow(1024, 576, "Leaf Project");
    InitAudioDevice();
    Music mainMusic = LoadMusicStream("music/main.mp3");
    SetTargetFPS(60);
    Cameraz mainCamera;
    createLevels(mainCamera);
    float delta{};
    Player player{mainCamera, &delta};
    PlayMusicStream(mainMusic);
    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        player.movement(level1.getPlatforms());
        BeginDrawing();
        ClearBackground(ccolors.blue);
        level1.drawLevel();
        player.drawPlayer();
        EndDrawing();
        UpdateMusicStream(mainMusic);
    }
    CloseWindow();
    return 0;
}
