#include "ball.h"

#include "raymath.h"

Ball ballCreate(Vector2 position, int angle) {
    return (Ball){
        .Position = position,
        .Angle = angle,
        .State = BallState_Moving,
    };
}
void ballUpdate(Ball *ball, float frameTime) {
    ball->Position =
        Vector2Add(ball->Position, Vector2Scale(ball->Velocity, frameTime));
    // TODO: Bouncing off of objects
	ball->Velocity = Vector2Rotate((Vector2){0, 1}, ball->Angle);
}
void ballDraw(Ball *ball) {
	DrawCircleV(ball->Position, 3, WHITE);
}
