#include "renderer.h"
#include "simulation.h"
#include <raylib.h>

void initSimulation(Simulation *sim) {
  sim->emitter.position = (Vector2){WIDTH / 2.0f, HEIGHT / 2.0f};
  sim->count = 0;
  sim->head = 0;
}

void updateEmitter(Emitter *emitter) {
  if (IsKeyDown(KEY_RIGHT))
    emitter->position.x += CAR_SPEED;
  if (IsKeyDown(KEY_LEFT))
    emitter->position.x -= CAR_SPEED;
  if (IsKeyDown(KEY_UP))
    emitter->position.y -= CAR_SPEED;
  if (IsKeyDown(KEY_DOWN))
    emitter->position.y += CAR_SPEED;
}

int main() {
  InitWindow(WIDTH, HEIGHT, "Doppler's Effect Simulator");
  SetTargetFPS(60);

  Simulation sim;
  initSimulation(&sim);

  float interval = 0.0f;
  float emitRate = 1.0f / WAVE_FREQUENCY;

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    updateEmitter(&sim.emitter);

    interval += dt;
    if (interval > emitRate) {
      emitWave(&sim);
      interval -= emitRate;
    }
    propogateWaves(&sim, dt);

    BeginDrawing();
    ClearBackground(BLACK);

    drawEmitter(&sim.emitter);
    drawWaves(&sim);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
