#include "simulation.h"

void emitWave(Simulation *sim) {
  sim->head = (sim->head + 1) % MAX_WAVES;
  sim->waves[sim->head] = (SoundWave){sim->emitter.position, 0.0f};

  if (sim->count < MAX_WAVES) {
    sim->count++;
  }
}

void propogateWaves(Simulation *sim, float dt) {
  for (int i = 0; i < sim->count; i++) {
    sim->waves[i].radius += WAVE_SPEED * dt;
  }
}