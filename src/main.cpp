#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/platform.hpp"
#include "../header/level.hpp"
#include "../header/camera.hpp"
#include "../header/guiBar.hpp"
#include <iostream>

int main()
{
    InitWindow(1024, 576, "Leaf Project");
    int test = 20;

    Cameraz mainCamera;
    createLevels(mainCamera);
    InitAudioDevice();
    Bar testBar(20, test, ccolors.red, ccolors.white, {1, 1, 9, 3}, mainCamera);
    Music mainMusic = LoadMusicStream("../music/main.mp3");

    if (IsMusicReady(mainMusic)) {
        PlayMusicStream(mainMusic);
    }

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_COMMA)) {
            test-=1;
            testBar.setCurrent(test);
            std::cout << test << std::endl;
        }
        else if (IsKeyPressed(KEY_P)) {
            test+=1;
            testBar.setCurrent(test);
            std::cout << test << std::endl;
        }
        BeginDrawing();
        ClearBackground(ccolors.blue);
        level1.drawLevel();
        testBar.draw();
        EndDrawing();
        UpdateMusicStream(mainMusic);
    }
    CloseWindow();
    return 0;
}
