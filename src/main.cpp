#include "../raylib/raylib.h"
#include "../header/menu.hpp"
#include "../header/imageImportation.hpp"
#include <iostream>

int main()
{
    InitWindow(1024, 576, "Leaf Project");
    InitAudioDevice();
    Music mainMusic = LoadMusicStream("music/main.mp3");
    SetTargetFPS(60);
    
    Menu menu{ImageCopy(screen_main_menu), ImageCopy(screen_loading), ImageCopy(growing_vine), ImageCopy(mana_bloc), ImageCopy(get_mana_bloc), ImageCopy(reload_mana_bloc), ImageCopy(reconstitution_mana_bloc), ImageCopy(textures_plateformes)};
    PlayMusicStream(mainMusic);
    while (!WindowShouldClose())
    {
        menu.playFrame();
        UpdateMusicStream(mainMusic);
    }
    CloseWindow();
    return 0;
}
