#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/platform.hpp"
#include "../header/level.hpp"
#include "../header/camera.hpp"

int main()
{
    InitWindow(1024, 576, "Leaf Project");
    Cameraz mainCamera;
    createLevels(mainCamera);
    InitAudioDevice();
    Music mainMusic = LoadMusicStream("../music/main.mp3");

    if (IsMusicReady(mainMusic)) {
        PlayMusicStream(mainMusic);
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(ccolors.blue);
        level1.drawLevel();
        EndDrawing();
        UpdateMusicStream(mainMusic);
    }
    CloseWindow();
    return 0;
}
