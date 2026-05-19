#pragma once
#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600
#define MAX_DEPTH 10
#define TIME_INTERVAL 0.7f

typedef struct {
  int depth;
  float interval;
  float x;
  float y;
  float w;
  float h;
  Vector2 baseV1;
  Vector2 baseV2;
  Vector2 baseV3;
} AppState;

void InitState(AppState *state);
void UpdateState(AppState *state);