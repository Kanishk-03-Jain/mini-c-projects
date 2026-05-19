#pragma once
#include "state.h"
#include <raylib.h>

void DrawScene(const AppState *state);
void makeTriangle(float x, float y, float w, float h, int depth);