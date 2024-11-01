#include "../raylib/raylib.h"
#include "../header/menu.hpp"
#include <iostream>

int main()
{
    InitWindow(1024, 576, "Leaf Project");
    InitAudioDevice();
    Music mainMusic = LoadMusicStream("music/main.mp3");
    SetTargetFPS(60);
    
    Menu menu{};
    PlayMusicStream(mainMusic);
    while (!WindowShouldClose())
    {
        menu.playFrame();
        UpdateMusicStream(mainMusic);
    }
    CloseWindow();
    return 0;
}
