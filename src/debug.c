#include "debug.h"

#include "globals.h"
#include "raygui.h"

const int yDiff = 20;
const int xPadding = 10;

bool debugFPS = true;
bool debugPaddles = true;
bool debugBall = true;
void debug(Paddle *paddles, Ball *ball) {
    Rectangle buttonBounds = {ScreenWidth - 110, xPadding, 100, yDiff + 10};
    GuiToggle(buttonBounds, "Paddles", &debugPaddles);
    buttonBounds.y += yDiff + 10;
    GuiToggle(buttonBounds, "FPS", &debugFPS);
    buttonBounds.y += yDiff + 10;
    GuiToggle(buttonBounds, "Ball", &debugBall);
    buttonBounds.y += yDiff + 10;

    int y = 10;
    if (debugFPS) {
        DrawFPS(xPadding, y);
        y += yDiff;
    }
    if (debugPaddles) {
        DrawText("Paddle 0:", xPadding, y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Position: (%.0f, %.0f)", paddles[0].Position.x,
                            paddles[0].Position.y),
                 xPadding, y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Velocity: %d", paddles[0].Velocity), xPadding,
                 y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Points: %d", paddles[0].Points), xPadding, y,
                 yDiff, LIME);
        y += yDiff;

        DrawText("Paddle 1:", xPadding, y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Position: (%.0f, %.0f)", paddles[1].Position.x,
                            paddles[1].Position.y),
                 xPadding, y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Velocity: %d", paddles[1].Velocity), xPadding,
                 y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Points: %d", paddles[0].Points), xPadding, y,
                 yDiff, LIME);
        y += yDiff;
    }
    if (debugBall) {
        DrawText("Ball:", xPadding, y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Position: (%.0f, %.0f)", ball->Position.x,
                            ball->Position.y),
                 xPadding, y, yDiff, LIME);
        y += yDiff;
        DrawText(TextFormat("	Angle: %d", ball->Angle), xPadding, y, yDiff,
                 LIME);
        y += yDiff;
        switch (ball->State) {
        case BallState_Moving:
            DrawText("	State: Moving", xPadding, y, yDiff, LIME);
            y += yDiff;
            break;
        case BallState_Resetting:
            DrawText("	State: Resetting", xPadding, y, yDiff, LIME);
            y += yDiff;
            break;
        }
    }
}
