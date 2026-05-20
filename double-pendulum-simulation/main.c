#include <raylib.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 600
#define LINE_THICKNESS 2
#define BOB_RADIUS 10
#define L1 200
#define L2 200
#define M1 1
#define M2 1
#define G 9.8f
#define TIME_PER_FRAME 8
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


Vector2 getEndPos(Vector2 pivot, int length, float theta) {
    float x_ = pivot.x + length * sinf(theta);
    float y_ = pivot.y + length * cosf(theta);

    return (Vector2){x_, y_};
}

void drawPendulum(Vector2 pivot, int length, float theta) {
    Vector2 endPos = getEndPos(pivot, length, theta);
    DrawLineEx(pivot, endPos, LINE_THICKNESS, WHITE);
    DrawCircleV(endPos, BOB_RADIUS, RED);
}

void updatePosition(Simulation *sim, float dt) {
    // updating angular accelerations
    sim->p1.alpha = (-G*(2*M1+M2)*sinf(sim->p1.theta) - M2*G*sinf(sim->p1.theta-2*sim->p2.theta) - 2*sinf(sim->p1.theta-sim->p2.theta)*M2*(sim->p2.omega*sim->p2.omega*L2+sim->p1.omega*sim->p1.omega*L1*cosf(sim->p1.theta-sim->p2.theta))) / (L1*(2*M1+M2-M2*cosf(2*sim->p1.theta-2*sim->p2.theta)));
    sim->p2.alpha = (2*sinf(sim->p1.theta-sim->p2.theta)*(sim->p1.omega*sim->p1.omega*L1*(M1+M2)+G*(M1+M2)*cosf(sim->p1.theta)+sim->p2.omega*sim->p2.omega*L2*M2*cosf(sim->p1.theta-sim->p2.theta))) / (L2*(2*M1+M2-M2*cosf(2*sim->p1.theta-2*sim->p2.theta)));

    // updating angular velocities
    sim->p1.omega += sim->p1.alpha * dt;
    sim->p2.omega += sim->p2.alpha * dt;

    // updating angular positions
    sim->p1.theta += sim->p1.omega * dt;
    sim->p2.theta += sim->p2.omega * dt;
}

void init(Simulation *sim) {
    sim->p1.theta = GetRandomValue(-90, 90) * DEG2RAD;
    sim->p2.theta = GetRandomValue(-90, 90) * DEG2RAD;
    sim->p1.omega = 0;
    sim->p2.omega = 0;
    sim->p1.alpha = 0;
    sim->p2.alpha = 0;

    sim->trail.head = 0;
    sim->trail.count = 0;
}

int main() {
    Simulation sim;
    sim.trail.points = (Vector2*)malloc(MAX_TRAIL * sizeof(Vector2));
    
    InitWindow(WIDTH, HEIGHT, "Double pendulum Simulation");
    SetTargetFPS(60);

    init(&sim);
    sim.p1.pivot = (Vector2){WIDTH/2, 0};
    
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        updatePosition(&sim, dt*TIME_PER_FRAME);
        
        if (IsKeyPressed(KEY_SPACE)) {
            init(&sim);
        }
        
        sim.p1.bob = getEndPos(sim.p1.pivot, L1, sim.p1.theta);
        sim.p2.pivot = sim.p1.bob;
        sim.p2.bob = getEndPos(sim.p1.bob, L2, sim.p2.theta);
        sim.trail.points[sim.trail.head] = sim.p2.bob;
        sim.trail.head = (sim.trail.head + 1) % MAX_TRAIL;

        if (sim.trail.count < MAX_TRAIL) sim.trail.count++;
        
        BeginDrawing();
            ClearBackground(BLACK);

            // pendulum 2
            drawPendulum(sim.p2.pivot, L2, sim.p2.theta);

            // draw pendulum 1
            drawPendulum(sim.p1.pivot, L1, sim.p1.theta);

            for (int i = 0; i < sim.trail.count; i++) {
                float opacity = (float)i / sim.trail.count;

                DrawCircleV(sim.trail.points[(i + sim.trail.head - sim.trail.count + MAX_TRAIL) % MAX_TRAIL], 3, Fade(RED, opacity));
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}