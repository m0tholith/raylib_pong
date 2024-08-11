#include "ball.h"

#include "globals.h"
#include "paddle.h"
#include "raymath.h"
#include <math.h>
#include <stdio.h>

extern Paddle *paddles;

const int radius = 4;

float resetCooldown = 0;

Ball ballCreate(Vector2 position, int angle) {
    return (Ball){
        .Position = position,
        .Angle = angle,
        .Velocity = Vector2Rotate((Vector2){0, -BallSpeed}, angle * DEG2RAD),
        .State = BallState_Moving,
        .RoundTimeStart = 0,
    };
}
void ballUpdate(Ball *ball, float frameTime) {
    float currentTime = GetTime();
    if (ball->State == BallState_Resetting) {
        resetCooldown -= frameTime;
        if (resetCooldown <= 0) {
            ball->State = BallState_Moving;
            ball->Position = ScreenCenter;
            ball->RoundTimeStart = currentTime;
        }
        return;
    }

    ball->Position = Vector2Add(
        ball->Position,
        Vector2Scale(ball->Velocity,
                     frameTime + (currentTime - ball->RoundTimeStart) *
                                     BallAcceleration / 4000));

    // 1. bouncing off of walls
    if (ball->Position.y < radius * 2 ||
        ball->Position.y > ScreenHeight - radius * 2) {
        ball->Angle = 180 - ball->Angle;
        ball->Angle %= 360;
        ball->Velocity =
            Vector2Rotate((Vector2){0, -BallSpeed}, ball->Angle * DEG2RAD);
    }

    // 2. bouncing off of paddles
    Rectangle paddleRec = {0, 0, PaddleDimensions.x, PaddleDimensions.y};
    for (int i = 0; i < 2; i++) {
        paddleRec.x = paddles[i].Position.x - PaddleDimensionsCenter.x;
        paddleRec.y = paddles[i].Position.y - PaddleDimensionsCenter.y;
        if (CheckCollisionCircleRec(ball->Position, radius, paddleRec)) {
            ball->Angle *= -1;
            ball->Angle %= 360;
            ball->Velocity =
                Vector2Rotate((Vector2){0, -BallSpeed}, ball->Angle * DEG2RAD);
            break;
        }
    }
    if (ball->Position.x > ScreenWidth) {
        paddles[1].Points++;
        ball->State = BallState_Resetting;
        resetCooldown = BallResetTime;
    } else if (ball->Position.x < 0) {
        paddles[0].Points++;
        ball->State = BallState_Resetting;
        resetCooldown = BallResetTime;
    }
}
void ballDraw(Ball *ball) {
    Color color = WHITE;
    float fmodResult = fmod(resetCooldown, 0.666f);
    if (ball->State == BallState_Resetting && fmodResult < 0.333f)
        color = BLACK;
    DrawCircleV(ball->Position, radius, color);
}
