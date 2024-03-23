#ifndef BALL_H_
#define BALL_H_

#include <raylib.h>

typedef enum BallState {
    BallState_Moving,
    BallState_Resetting,
} BallState;
typedef struct Ball {
    Vector2 Position;
    Vector2 Velocity;
    int Angle;
    BallState state;
} Ball;

Ball ballCreate(Vector2 position, int angle);
void ballUpdate(Ball *ball, float frameTime);
void ballDraw(Ball *ball);

#endif
