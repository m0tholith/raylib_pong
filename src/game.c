#include "debug.h"
#include "globals.h"
#include "paddle.h"
#include "raylib.h"
#include "stdlib.h"

Paddle *paddles;

bool debugMode = false;

int main(void) {
    InitWindow(ScreenWidth, ScreenHeight, "game");
    // InitAudioDevice();
    SetTargetFPS(FPS);

    paddles = malloc(2 * sizeof(Paddle));
    paddles[0] = paddleCreate(ScreenWidth / 4);
    paddles[1] = paddleCreate(3 * ScreenWidth / 4);

    float frameTime = 0;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        paddles[0].Velocity =
            (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * PaddleSpeed;
        paddles[1].Velocity =
            (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP)) * PaddleSpeed;

        frameTime = GetFrameTime();

        paddleUpdate(paddles + 0, frameTime);
        paddleDraw(paddles + 0);
        paddleUpdate(paddles + 1, frameTime);
        paddleDraw(paddles + 1);

        if (IsKeyPressed(KEY_TAB))
            debugMode = !debugMode;

        if (debugMode)
            debug(paddles);

        EndDrawing();
    }

	free(paddles);
    // CloseAudioDevice();
    CloseWindow();

    return 0;
}
