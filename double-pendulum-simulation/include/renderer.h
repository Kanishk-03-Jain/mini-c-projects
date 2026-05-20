#pragma once
#include "include/simulation.h"
#define WIDTH 900
#define HEIGHT 600
#define LINE_THICKNESS 2
#define BOB_RADIUS 10

#define TIME_PER_FRAME 8

void drawPendulum(Pendulum *pendulum);
void drawTrail(Simulation *sim);