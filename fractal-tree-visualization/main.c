#include <raylib.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 800

#define ANGLE PI/11.0f
#define RATIO 0.75f
#define DEPTH 14
#define INITIAL_LEN 200
#define INITIAL_THICHNESS 20

typedef struct {
    float length;
    float theta;
    float thickness;
    Vector2 startPos;
} Branch;

Vector2 getEndPos(Branch *branch) {
    float x = branch->length * sinf(branch->theta);
    float y = branch->length * cosf(branch->theta);
    return (Vector2) {branch->startPos.x + x, branch->startPos.y - y};
}

void drawBranch(Branch *branch) {
    Vector2 endPos = getEndPos(branch);
    DrawLineEx(branch->startPos, endPos, branch->thickness, WHITE);
}

void drawFractal(Branch *branch, int depth) {
    if (depth == 0) {
        return;
    }
    drawBranch(branch);
    Branch left, right;
    left.length = branch->length * RATIO;
    left.startPos = getEndPos(branch);
    left.theta = branch->theta - ANGLE;
    left.thickness = branch->thickness * RATIO;

    right.length = branch->length * RATIO;
    right.startPos = getEndPos(branch);
    right.theta = branch->theta + ANGLE;
    right.thickness = branch->thickness * RATIO;

    drawFractal(&left, depth - 1);
    drawFractal(&right, depth - 1);

}

int main() {
    InitWindow(WIDTH, HEIGHT, "Fractal Tree Visualizer");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            Branch branch;
            branch.length = INITIAL_LEN;
            branch.theta = 0;
            branch.thickness = INITIAL_THICHNESS;
            branch.startPos = (Vector2){ WIDTH / 2, HEIGHT - 5};

            drawFractal(&branch, DEPTH);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}