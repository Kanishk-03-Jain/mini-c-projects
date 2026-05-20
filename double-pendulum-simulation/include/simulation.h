#pragma once
#include <raylib.h>

#define L1 200
#define L2 200
#define M1 1
#define M2 1
#define G 9.8f
#define MAX_TRAIL 150


typedef struct {
    float theta;    // angular position
    float omega;    // angular velocity
    float alpha;    // angular acceleration

    int length;     // length of the rod
    int mass;       // mass of the bob

    Vector2 pivot;  // pivot position (start pos)
    Vector2 bob;    // position of bob (end pos)
} Pendulum;

typedef struct {
    Vector2 *points;
    int head;
    int count;
} Trail;

typedef struct {
    Pendulum p1;
    Pendulum p2;
    Trail trail;
} Simulation;


Vector2 getBobPos(Pendulum *pendulum);
void updatePosition(Simulation *sim, float dt);
void init(Simulation *sim);