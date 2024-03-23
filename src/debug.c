#include "debug.h"

#include "globals.h"
#include "raygui.h"

bool debugPaddles = true;
bool debugFPS = true;
int diff = 20;
void debug(Paddle *paddles) {
    Rectangle buttonBounds = {ScreenWidth - 110, 10, 100, 20};
    GuiToggle(buttonBounds, "Paddles", &debugPaddles);
    buttonBounds.y += diff;
    GuiToggle(buttonBounds, "FPS", &debugFPS);

    int y = 10;
    if (debugFPS) {
        DrawFPS(10, y);
        y += diff;
    }
    if (debugPaddles) {
        DrawText("Paddle 0:", 10, y, 20, LIME);
        y += diff;
        DrawText(TextFormat("	Position: (%.0f, %.0f)", paddles[0].Position.x,
                            paddles[0].Position.y),
                 10, y, 20, LIME);
        y += diff;
        DrawText(TextFormat("	Velocity: %d", paddles[0].Velocity), 10, y, 20,
                 LIME);
        y += diff;

        DrawText("Paddle 1:", 10, y, 20, LIME);
        y += diff;
        DrawText(TextFormat("	Position: (%.0f, %.0f)", paddles[1].Position.x,
                            paddles[1].Position.y),
                 10, y, 20, LIME);
        y += diff;
        DrawText(TextFormat("	Velocity: %d", paddles[1].Velocity), 10, y, 20,
                 LIME);
        y += diff;
    }
}
