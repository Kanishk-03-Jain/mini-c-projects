#include "simulation.h"
#include <raylib.h>

void drawEmitter(Emitter *emitter) {
  DrawCircleV(emitter->position, 20, WHITE);
}

void drawWaves(Simulation *sim) {
  for (int i = 0; i < sim->count; i++) {
    DrawCircleLinesV(sim->waves[i].position, sim->waves[i].radius, WHITE);
  }
}