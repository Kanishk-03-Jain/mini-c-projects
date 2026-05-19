#include "../include/state.h"
#include <math.h>
#include <raylib.h>

void InitState(AppState *state) {
  state->depth = 0;
  state->interval = 0;

  state->h = HEIGHT - 10;
  state->w = 2 * state->h * tanf(30 * DEG2RAD);
  state->x = (WIDTH - 10) / 2.0f - state->w / 2.0f;
  state->y = 5;

  state->baseV1 = (Vector2){state->x + state->w / 2, state->y};
  state->baseV2 = (Vector2){state->x, state->y + state->h};
  state->baseV3 = (Vector2){state->x + state->w, state->y + state->h};
}

void UpdateState(AppState *state) {
  if (IsKeyPressed(KEY_SPACE)) {
    state->depth = 0;
  }

  float dt = GetFrameTime();
  state->interval += dt;

  if (state->interval > TIME_INTERVAL) {
    if (state->depth < MAX_DEPTH) {
      state->depth++;
    }
    state->interval -= TIME_INTERVAL;
  }
}
