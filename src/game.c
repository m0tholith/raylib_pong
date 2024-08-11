#include "raylib.h"
#include <stdlib.h>

#include "ball.h"
#include "debug.h"
#include "globals.h"
#include "paddle.h"

Paddle *paddles;
Ball ball;

bool debugMode = false;
#define PADDLE_POSITION_X 400

int main(void) {
    InitWindow(ScreenWidth, ScreenHeight - 36, "game");
    // InitAudioDevice();
    SetTargetFPS(FPS);

    paddles = malloc(2 * sizeof(Paddle));
    paddles[0] = paddleCreate(ScreenWidth / 2 - PADDLE_POSITION_X);
    paddles[1] = paddleCreate(ScreenWidth / 2 + PADDLE_POSITION_X);

    ball = ballCreate(ScreenCenter, -45);

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

        ballUpdate(&ball, frameTime);
        ballDraw(&ball);

        if (ball.State == BallState_Resetting) {
            const char *textP0 = TextFormat("%d", paddles[0].Points);
            const char *textP1 = TextFormat("%d", paddles[1].Points);
            DrawText(textP0, ScreenWidth / 4 + 50, 50, 120, WHITE);
            DrawText(textP1,
                     3 * ScreenWidth / 4 - 50 - MeasureText(textP1, 120), 50,
                     120, WHITE);
        }

        if (IsKeyPressed(KEY_TAB))
            debugMode = !debugMode;

        if (debugMode)
            debug(paddles, &ball);

        EndDrawing();
    }

    free(paddles);
    // CloseAudioDevice();
    CloseWindow();

    return 0;
}
