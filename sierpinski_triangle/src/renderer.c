#include "../include/state.h"
#include <raylib.h>

void makeTriangle(float x, float y, float w, float h, int depth) {
  if (depth == 0)
    return;
  Vector2 v1 = (Vector2){x + w / 2, y + h};
  Vector2 v2 = (Vector2){x + 3 * w / 4, y + h / 2};
  Vector2 v3 = (Vector2){x + w / 4, y + h / 2};

  DrawTriangle(v1, v2, v3, BLACK);

  makeTriangle(x + w / 4, y, w / 2, h / 2, depth - 1);
  makeTriangle(x, y + h / 2, w / 2, h / 2, depth - 1);
  makeTriangle(x + w / 2, y + h / 2, w / 2, h / 2, depth - 1);
}

void DrawScene(const AppState *state) {
  BeginDrawing();
  ClearBackground(BLACK);

  DrawTriangle(state->baseV1, state->baseV2, state->baseV3, WHITE);
  makeTriangle(state->x, state->y, state->w, state->h, state->depth);

  EndDrawing();
}