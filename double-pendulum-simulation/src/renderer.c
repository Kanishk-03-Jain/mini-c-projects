#include "include/renderer.h"
#include "include/simulation.h"

// including raygui and silencing its warnings
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

#pragma GCC diagnostic pop

void drawPendulum(Pendulum* pendulum)
{
    float visualRadius = BOB_RADIUS + (pendulum->mass * 0.5f);
    DrawLineEx(pendulum->pivot, pendulum->bob, LINE_THICKNESS, WHITE);
    DrawCircleV(pendulum->bob, visualRadius, RED);
}

void drawTrail(Simulation* sim)
{
    for (int i = 0; i < sim->trail.count; i++) {
        float opacity = (float)i / sim->trail.count;

        DrawCircleV(
        sim->trail.points[(i + sim->trail.head - sim->trail.count + MAX_TRAIL) %
                            MAX_TRAIL],
        3,
        Fade(RED, opacity)
        );
    }
}

void renderUIPanel(Simulation* sim)
{
    DrawRectangle(10, UI_PANEL_START + 10, 200, 150, Fade(DARKGRAY, 0.8f));
    DrawText("CONTROLS", 20, UI_PANEL_START + 20, 10, WHITE);

    GuiSlider((Rectangle){ 60, UI_PANEL_START + 40, 100, 15 },
                "L1",
                TextFormat("%.0f", sim->p1.length),
                &sim->p1.length,
                30,
                300);

    GuiSlider((Rectangle){ 60, UI_PANEL_START + 65, 100, 15 },
                "L2",
                TextFormat("%.0f", sim->p2.length),
                &sim->p2.length,
                30,
                300);
    GuiSlider((Rectangle){ 60, UI_PANEL_START + 90, 100, 15 },
                "M1",
                TextFormat("%.0f", sim->p1.mass),
                &sim->p1.mass,
                0.5f,
                5.0f);
    GuiSlider((Rectangle){ 60, UI_PANEL_START + 115, 100, 15 },
                "M2",
                TextFormat("%.0f", sim->p2.mass),
                &sim->p2.mass,
                0.5f,
                5.0f);

    DrawText("Press SPACE to reset", 20, UI_PANEL_START + 140, 10, LIGHTGRAY);
}