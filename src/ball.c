#include "ball.h"

#include "globals.h"
#include "paddle.h"
#include "raymath.h"

extern Paddle *paddles;

const int radius = 3;

Ball ballCreate(Vector2 position, int angle) {
    return (Ball){
        .Position = position,
        .Angle = angle,
        .Velocity = Vector2Rotate((Vector2){0, -BallSpeed}, angle / RAD2DEG),
        .State = BallState_Moving,
    };
}
void ballUpdate(Ball *ball, float frameTime) {
    ball->Position =
        Vector2Add(ball->Position, Vector2Scale(ball->Velocity, frameTime));

    // 1. bouncing off of walls
    if (ball->Position.y < radius * 2 ||
        ball->Position.y > ScreenHeight - radius * 2) {
        ball->Angle = 180 - ball->Angle;
        ball->Angle %= 360;
        ball->Velocity =
            Vector2Rotate((Vector2){0, -BallSpeed}, ball->Angle / RAD2DEG);
    }

    // 2. bouncing off of paddles
    Rectangle paddleRec = {0, 0, PaddleDimensions.x, PaddleDimensions.y};
    DrawText(TextFormat("%d", ball->Angle), 10, ScreenHeight - 30, 20, WHITE);
    for (int i = 0; i < 2; i++) {
        paddleRec.x = paddles[i].Position.x - PaddleDimensionsCenter.x;
        paddleRec.y = paddles[i].Position.y - PaddleDimensionsCenter.y;
        if (CheckCollisionCircleRec(ball->Position, radius, paddleRec)) {
            ball->Angle *= -1;
            ball->Angle %= 360;
            ball->Velocity =
                Vector2Rotate((Vector2){0, -BallSpeed}, ball->Angle / RAD2DEG);
            break;
        }
    }
}
void ballDraw(Ball *ball) { DrawCircleV(ball->Position, radius, WHITE); }
