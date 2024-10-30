#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/platform.hpp"
#include "../header/level.hpp"
#include "../header/camera.hpp"
#include "../header/guiBar.hpp"
#include "../header/player.hpp"
#include "../header/imageImportation.hpp"

int main()
{
    InitWindow(1024, 576, "Leaf Project");
    InitAudioDevice();
    Music mainMusic = LoadMusicStream("music/main.mp3");
    SetTargetFPS(60);

    Cameraz mainCamera;
    createLevels(&mainCamera);
    float delta{};
    Player player{&mainCamera, &delta, ImageCopy(caractere)};

    Bar manaBar(20, player.getMana(), ccolors.lightGreen, ccolors.white, {15, 15, 300, 25}, &mainCamera);


    PlayMusicStream(mainMusic);
    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        player.movement(level1.getPlatforms());
        player.manaDebugTest(); //Comment to deactivate debug of mana and modification
        cameraFollowPlayer(&mainCamera, &player);
        BeginDrawing();
        ClearBackground(ccolors.blue);
        level1.drawLevel();
        player.drawPlayer();
        manaBar.setCurrent(player.getMana());
        manaBar.draw();
        EndDrawing();
        UpdateMusicStream(mainMusic);
    }
    CloseWindow();
    return 0;
}
