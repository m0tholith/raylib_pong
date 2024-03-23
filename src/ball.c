#include "ball.h"

#include "globals.h"
#include "raymath.h"

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
    // TODO: Bouncing off of objects
    // 1. bouncing off of walls
    if (ball->Position.y < radius * 2 ||
        ball->Position.y > ScreenHeight - radius * 2) {
        ball->Angle = 180 - ball->Angle;
        ball->Velocity =
            Vector2Rotate((Vector2){0, -BallSpeed}, ball->Angle / RAD2DEG);
    }
}
void ballDraw(Ball *ball) { DrawCircleV(ball->Position, radius, WHITE); }
