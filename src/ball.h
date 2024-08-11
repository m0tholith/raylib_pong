#ifndef BALL_H_
#define BALL_H_

#include "raylib.h"

static const int BallSpeed = 350;
static const float BallResetTime = 2.0f;
static const float BallAcceleration = 2;
typedef enum BallState {
    BallState_Moving,
    BallState_Resetting,
} BallState;
typedef struct Ball {
    Vector2 Position;
    Vector2 Velocity;
    int Angle;
    BallState State;
	float RoundTimeStart;
} Ball;

Ball ballCreate(Vector2 position, int angle);
void ballUpdate(Ball *ball, float frameTime);
void ballDraw(Ball *ball);

#endif
