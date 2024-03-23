#include "paddle.h"

#include "globals.h"
#include "raymath.h"

Paddle paddleCreate(int position) {
    return (Paddle){
        .Position = (Vector2){position, ScreenCenter.y},
        .Velocity = 0,
        .Points = 0,
    };
}
void paddleUpdate(Paddle *paddle, float frameTime) {
    paddle->Position.y += paddle->Velocity * frameTime;
    paddle->Position.y = Clamp(paddle->Position.y, PaddleDimensionsCenter.y,
                               ScreenHeight - PaddleDimensionsCenter.y);
}
void paddleDraw(Paddle *paddle) {
    DrawRectangleV(Vector2Subtract(paddle->Position, PaddleDimensionsCenter),
                   PaddleDimensions, WHITE);
}
