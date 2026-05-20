#include "include/renderer.h"
#include "include/simulation.h"

void drawPendulum(Pendulum *pendulum) {
    DrawLineEx(pendulum->pivot, pendulum->bob, LINE_THICKNESS, WHITE);
    DrawCircleV(pendulum->bob, BOB_RADIUS, RED);
}

void drawTrail(Simulation *sim) {
    for (int i = 0; i < sim->trail.count; i++) {
        float opacity = (float)i / sim->trail.count;

        DrawCircleV(
            sim->trail.points[(i + sim->trail.head - sim->trail.count + MAX_TRAIL) % MAX_TRAIL], 
            3, 
            Fade(RED, opacity)
        );
    }
}