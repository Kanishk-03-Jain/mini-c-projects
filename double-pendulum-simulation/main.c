#include <raylib.h>
#include <math.h>

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

Vector2 trail[MAX_TRAIL];
int trailHead;
int trailCount;

float theta1;
float theta2;
float omega1;
float omega2;
float alpha1;
float alpha2;

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

void updatePosition(float dt) {
    alpha1 = (-G*(2*M1+M2)*sinf(theta1) - M2*G*sinf(theta1-2*theta2) - 2*sinf(theta1-theta2)*M2*(omega2*omega2*L2+omega1*omega1*L1*cosf(theta1-theta2))) / (L1*(2*M1+M2-M2*cosf(2*theta1-2*theta2)));
    alpha2 = (2*sinf(theta1-theta2)*(omega1*omega1*L1*(M1+M2)+G*(M1+M2)*cosf(theta1)+omega2*omega2*L2*M2*cosf(theta1-theta2))) / (L2*(2*M1+M2-M2*cosf(2*theta1-2*theta2)));

    omega1 += alpha1 * dt;
    omega2 += alpha2 * dt;

    theta1 += omega1 * dt;
    theta2 += omega2 * dt;
}

void initPos() {
    theta1 = GetRandomValue(-90, 90) * DEG2RAD;
    theta2 = GetRandomValue(-90, 90) * DEG2RAD;
    omega1 = 0;
    omega2 = 0;
    alpha1 = 0;
    alpha2 = 0;
    trailHead = 0;
    trailCount = 0;
}

int main() {
    InitWindow(WIDTH, HEIGHT, "Double pendulum Simulation");
    SetTargetFPS(60);

    Vector2 pivot1 = (Vector2){WIDTH/2, 0};
    initPos();
    
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        updatePosition(dt*TIME_PER_FRAME);
        
        if (IsKeyPressed(KEY_SPACE)) {
            initPos();
        }
        
        Vector2 bob1 = getEndPos(pivot1, L1, theta1);
        Vector2 bob2 = getEndPos(bob1, L2, theta2);
        trail[trailHead] = bob2;
        trailHead = (trailHead + 1) % MAX_TRAIL;

        if (trailCount < MAX_TRAIL) trailCount++;
        
        BeginDrawing();
            ClearBackground(BLACK);

            // pendulum 2
            drawPendulum(bob1, L2, theta2);

            // draw pendulum 1
            drawPendulum(pivot1, L1, theta1);

            for (int i = 0; i < trailCount; i++) {
                float opacity = (float)i / trailCount;

                DrawCircleV(trail[(i + trailHead - trailCount + MAX_TRAIL) % MAX_TRAIL], 3, Fade(RED, opacity));
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}