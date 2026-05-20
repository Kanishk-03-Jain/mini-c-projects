#include <raylib.h>
#include <math.h>
#include <stdlib.h>

#include "include/renderer.h"
#include "include/simulation.h"

int main() {
    Simulation sim;
    sim.trail.points = (Vector2*)malloc(MAX_TRAIL * sizeof(Vector2));
    
    InitWindow(WIDTH, HEIGHT, "Double pendulum Simulation");
    SetTargetFPS(60);

    init(&sim);
    sim.p1.pivot = (Vector2){WIDTH/2, 0};
    
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        updatePosition(&sim, dt*TIME_PER_FRAME);
        
        if (IsKeyPressed(KEY_SPACE)) {
            init(&sim);
        }
        
        sim.p1.bob = getBobPos(&sim.p1);
        sim.p2.pivot = sim.p1.bob;
        sim.p2.bob = getBobPos(&sim.p2);
        sim.trail.points[sim.trail.head] = sim.p2.bob;
        sim.trail.head = (sim.trail.head + 1) % MAX_TRAIL;

        if (sim.trail.count < MAX_TRAIL) sim.trail.count++;
        
        BeginDrawing();
            ClearBackground(BLACK);

            // draw pendulums
            drawPendulum(&sim.p2);
            drawPendulum(&sim.p1);

            // draw trail
            drawTrail(&sim);

        EndDrawing();
    }

    CloseWindow();
    free(sim.trail.points);
    return 0;
}