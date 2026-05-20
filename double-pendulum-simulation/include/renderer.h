#pragma once
#include "simulation.h"
#define WIDTH 900
#define HEIGHT 600
#define LINE_THICKNESS 2
#define BOB_RADIUS 10

#define TIME_PER_FRAME 8

#define UI_PANEL_START (HEIGHT - 170)

void drawPendulum(Pendulum *pendulum);
void drawTrail(Simulation *sim);
void renderUIPanel(Simulation *sim);