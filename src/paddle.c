#include "paddle.h"

#include "globals.h"
#include "raymath.h"

Vector2 dimensions = {6, 60};
Vector2 dimensionsCenter = {3, 30};

Paddle paddleCreate(int position) {
    return (Paddle){
        .Position = (Vector2){position, ScreenCenter.y},
        .Velocity = 0,
        .Points = 0,
    };
}
void paddleUpdate(Paddle *paddle, float frameTime) {
    paddle->Position.y += paddle->Velocity * frameTime;
    paddle->Position.y = Clamp(paddle->Position.y, dimensionsCenter.y,
                               ScreenHeight - dimensionsCenter.y);
}
void paddleDraw(Paddle *paddle) {
    DrawRectangleV(Vector2Subtract(paddle->Position, dimensionsCenter),
                   dimensions, WHITE);
}
