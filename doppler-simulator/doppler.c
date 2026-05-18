#include <stdio.h>
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
    int head;   // Index of the newest wave
    int count;  // Number of active waves
} Simulation;

void initSimulation(Simulation *sim) {
    sim->emitter.position = (Vector2){ WIDTH / 2.0f, HEIGHT / 2.0f };
    sim->head = 0;
    sim->count = 0;
}

void updateEmitter(Emitter *emitter) {
    if (IsKeyDown(KEY_RIGHT)) emitter->position.x += CAR_SPEED;
    if (IsKeyDown(KEY_LEFT)) emitter->position.x -= CAR_SPEED;
    if (IsKeyDown(KEY_UP)) emitter->position.y -= CAR_SPEED;
    if (IsKeyDown(KEY_DOWN)) emitter->position.y += CAR_SPEED;
}

void emitWave(Simulation *sim) {
    sim->head = (sim->head + 1) % MAX_WAVES;
    sim->waves[sim->head] = (SoundWave){ sim->emitter.position, 0.0f };
    if (sim->count < MAX_WAVES) {
        sim->count++;
    }
}

void propagateWaves(Simulation *sim, float dt) {
    for (int i = 0; i < sim->count; i++) {
        sim->waves[i].radius += WAVE_SPEED * dt;
    }
}

void drawEmitter(const Emitter *emitter) {
    DrawCircleV(emitter->position, 20, WHITE);
}

void drawWaves(const Simulation *sim) {
    for (int i = 0; i < sim->count; i++) {
        DrawCircleLines((int)sim->waves[i].position.x, (int)sim->waves[i].position.y, sim->waves[i].radius, WHITE);
    }
}

int main(void) {
    InitWindow(WIDTH, HEIGHT, "Doppler Effect Simulator");
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
        
        propagateWaves(&sim, dt);

        BeginDrawing();
        ClearBackground(BLACK);

        drawEmitter(&sim.emitter);
        drawWaves(&sim);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
