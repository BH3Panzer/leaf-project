#include "../raylib/raylib.h"
#include "../header/colors.hpp"
#include "../header/platform.hpp"
#include "../header/level.hpp"
#include "../header/camera.hpp"

int main() {
    InitWindow(1024, 576, "Leaf Project");
    struct Ccolors ccolors;
    createLevels(mainCamera);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(ccolors.blue);
        level1.drawLevel();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
