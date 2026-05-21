#include "include/renderer.h"
#include "include/state.h"

#include <raylib.h>

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal Tree Visualizer");
    SetTargetFPS(60);

    int depth = 0;
    float time = 0;
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            depth = 0;
        }
        time += GetFrameTime();

        if (time >= 0.25f) {
            if (depth < MAX_DEPTH)
                depth++;
            time = 0;
        }

        BeginDrawing();
            ClearBackground(BLACK);

            Branch branch;
            init(&branch);
            drawFractal(&branch, depth);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}