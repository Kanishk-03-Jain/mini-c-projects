#include "include/renderer.h"
#include "include/state.h"

int main(void) {
  InitWindow(WIDTH, HEIGHT, "Sierpinski's Triangle");
  SetTargetFPS(60);

  AppState state;
  InitState(&state);

  while (!WindowShouldClose()) {
    UpdateState(&state);
    DrawScene(&state);
  }
  CloseWindow();
  return 0;
}
