#include "../raylib/raylib.h"

int main() {
    InitWindow(1024, 576, "Leaf Project");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
