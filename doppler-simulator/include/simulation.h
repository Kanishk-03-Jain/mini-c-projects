#pragma once
#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600
#define MAX_WAVES 50
#define WAVE_SPEED 100
#define WAVE_FREQUENCY 6
#define CAR_SPEED 1.0f

typedef struct {
  Vector2 position;
} Emitter;

typedef struct {
  Vector2 position;
  float radius;
} SoundWave;

typedef struct {
  Emitter emitter;
  SoundWave waves[MAX_WAVES];
  int count;
  int head;
} Simulation;

void emitWave(Simulation *sim);
void propogateWaves(Simulation *sim, float dt);
