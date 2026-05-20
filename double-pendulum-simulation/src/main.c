#include <math.h>
#include <raylib.h>
#include <stdlib.h>

#include "include/renderer.h"
#include "include/simulation.h"

int main()
{
    Simulation sim;
    sim.trail.points = (Vector2 *)malloc(MAX_TRAIL * sizeof(Vector2));

    InitWindow(WIDTH, HEIGHT, "Double pendulum Simulation");
    SetTargetFPS(60);

    init(&sim);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        updateSimulationState(&sim, dt * TIME_PER_FRAME);

        if (IsKeyPressed(KEY_SPACE))
        {
            init(&sim);
        }

        BeginDrawing();
            ClearBackground(BLACK);

            // draw pendulums
            drawPendulum(&sim.p2);
            drawPendulum(&sim.p1);

            // draw trail
            drawTrail(&sim);

            // render Control UI Panel
            renderUIPanel(&sim);

        EndDrawing();
    }

    CloseWindow();
    free(sim.trail.points);
    return 0;
}