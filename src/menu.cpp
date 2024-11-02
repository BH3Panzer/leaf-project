#include "../header/menu.hpp"
#include <iostream>

void Menu::drawLoadingScreen()
{
    BeginDrawing();
    DrawTexture(this->screenLoading, 0, 0, WHITE);
    EndDrawing();
}


Menu::Menu(Image screenMainMenu, Image screenLoading, Image growingVine, Image manaBloc, Image getManaBloc, Image reloadManaBloc, Image reconstitutionManaBloc, Image texturesPlateformes, int levelNumber)
{
    ImageResizeNN(&screenLoading, GetScreenWidth(), GetScreenHeight());
    this->screenLoading = LoadTextureFromImage(screenLoading);
    drawLoadingScreen();

    ImageResizeNN(&screenMainMenu, GetScreenWidth(), GetScreenHeight());
    this->screenMainMenu = LoadTextureFromImage(screenMainMenu);

    ImageResizeNN(&growingVine, (int)(16 * mainCamera.scale), (int)(576 * mainCamera.scale));
    this->growingVineVertical = LoadTextureFromImage(growingVine);
    ImageRotateCW(&growingVine);
    this->growingVineFLeftHorizontal = LoadTextureFromImage(growingVine);
    ImageFlipHorizontal(&growingVine);
    this->growingVineFRightHorizontal = LoadTextureFromImage(growingVine);

    ImageResizeNN(&manaBloc, (int)(16 * mainCamera.scale), (int)(16 * mainCamera.scale));
    this->manaBloc = LoadTextureFromImage(manaBloc);
    ImageResizeNN(&getManaBloc, (int)(16 * mainCamera.scale), (int)(112 * mainCamera.scale));
    this->getManaBloc = LoadTextureFromImage(getManaBloc);
    ImageResizeNN(&reloadManaBloc, (int)(16 * mainCamera.scale), (int)(128 * mainCamera.scale));
    this->reloadManaBloc = LoadTextureFromImage(reloadManaBloc);
    ImageResizeNN(&reconstitutionManaBloc, (int)(16 * mainCamera.scale), (int)(128 * mainCamera.scale));
    this->reconstitutionManaBloc = LoadTextureFromImage(reconstitutionManaBloc);

    ImageResizeNN(&texturesPlateformes, (int)(160 * mainCamera.scale), (int)(16 * mainCamera.scale));
    this->texturesPlateformes = LoadTextureFromImage(texturesPlateformes);

    this->player = Player(&mainCamera, &delta, ImageCopy(caractere), ImageCopy(caractereRun), ImageCopy(caractereJump), ImageCopy(caractere_concentration),
        ImageCopy(caractere_growing), ImageCopy(caractere_bridge));

    this->manaBar = Bar(20, player.getMana(), ccolors.lightGreen, ccolors.white, {15, 15, 300, 25}, &mainCamera);
    this->level = createLevel(levelNumber, &mainCamera, &player, &delta, &this->growingVineVertical, &this->growingVineFLeftHorizontal, &this->growingVineFRightHorizontal,
        &this->manaBloc, &this->getManaBloc, &this->reloadManaBloc, &this->reconstitutionManaBloc, &this->texturesPlateformes);
    this->levelNumber = levelNumber;

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
    this->player.recoverManaBloc(&this->level);
    this->level.actualisateManaBlocs();
    this->player.manaDebugTest(); // Comment to deactivate debug of mana and modification
    cameraDebugTest(&this->mainCamera); // Comment to deactivate debug of camera scale
    cameraFollowPlayerF(&this->mainCamera, &this->player, this->delta);
    cameraMove(&this->mainCamera, this->delta);
    this->handleLevels();

    BeginDrawing();
    ClearBackground(ccolors.blue);
    this->level.drawLevel();
    this->player.drawPlayer();
    this->manaBar.setCurrent(this->player.getMana());
    this->manaBar.draw();
    EndDrawing();
}

void Menu::handleLevels() {
    this->level.checkLevelFinished();
    if (this->level.isFinished()) {
        this->levelNumber += 1;
        this->level = createLevel(this->levelNumber, &this->mainCamera, &this->player, &this->delta, &this->growingVineVertical, &this->growingVineFLeftHorizontal, &this->growingVineFRightHorizontal,
        &this->manaBloc, &this->getManaBloc, &this->reloadManaBloc, &this->reconstitutionManaBloc, &this->texturesPlateformes);
        this->player.setPosition(5, 5);
    }
}
