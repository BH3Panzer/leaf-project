#include "../header/menu.hpp"
#include <iostream>
Menu::Menu()
{
    //ImageResizeNN(&screenMainMenu, GetScreenWidth(), GetScreenHeight());
    //this->screenMainMenu = LoadTextureFromImage(screenMainMenu);
    this->player = Player(&mainCamera, &delta, ImageCopy(caractere), ImageCopy(caractereRun), ImageCopy(caractereJump), ImageCopy(caractere_concentration),
        ImageCopy(caractere_growing), ImageCopy(caractere_bridge));

    this->manaBar = Bar(20, player.getMana(), ccolors.lightGreen, ccolors.white, {15, 15, 300, 25}, &mainCamera);
    this->level = createLevel(1, &mainCamera, &player, &delta, ImageCopy(growing_vine));
}

void Menu::drawMainMenu()
{

}

void Menu::playFrame()
{
    this->delta = GetFrameTime();
    this->player.movement(this->level.getPlatforms(), this->level.getPlants());
    this->player.handleInterract(&this->level);
    this->level.actualisatePlant();
    this->player.manaDebugTest(); // Comment to deactivate debug of mana and modification
    cameraDebugTest(&this->mainCamera); // Comment to deactivate debug of camera scale
    cameraFollowPlayerF(&this->mainCamera, &this->player, this->delta);
    cameraMove(&this->mainCamera, this->delta);

    BeginDrawing();
    ClearBackground(ccolors.blue);
    this->level.drawLevel();
    this->player.drawPlayer();
    this->manaBar.setCurrent(this->player.getMana());
    this->manaBar.draw();
    EndDrawing();
}