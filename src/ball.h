#ifndef BALL_H_
#define BALL_H_

#include "raylib.h"

static const int BallSpeed = 500;
static const float ResetTime = 2.0f;
typedef enum BallState {
    BallState_Moving,
    BallState_Resetting,
} BallState;
typedef struct Ball {
    Vector2 Position;
    Vector2 Velocity;
    int Angle;
    BallState State;
} Ball;

Ball ballCreate(Vector2 position, int angle);
void ballUpdate(Ball *ball, float frameTime);
void ballDraw(Ball *ball);

#endif
