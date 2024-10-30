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
    float delta{};
    Player player{&mainCamera, &delta, ImageCopy(caractere), ImageCopy(caractereRun), ImageCopy(caractereJump)};

    Bar manaBar(20, player.getMana(), ccolors.lightGreen, ccolors.white, {15, 15, 300, 25}, &mainCamera);
    Level level1 = createLevel1(&mainCamera, &player);

    PlayMusicStream(mainMusic);
    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        player.movement(level1.getPlatforms());
        level1.handleInterract();
        player.manaDebugTest(); // Comment to deactivate debug of mana and modification
        cameraDebugTest(&mainCamera); // Comment to deactivate debug of camera scale
        cameraFollowPlayer(&mainCamera, &player);
        cameraMove(&mainCamera, delta);
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
