#ifndef PADDLE_H_
#define PADDLE_H_

#include "raylib.h"

static const int PaddleSpeed = 1000;

typedef struct Paddle {
    Vector2 Position;
    int Velocity;
    int Points;
} Paddle;

Paddle paddleCreate(int position);
void paddleUpdate(Paddle *paddle, float frameTime);
void paddleDraw(Paddle *paddle);

#endif
