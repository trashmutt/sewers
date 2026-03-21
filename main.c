#include "raylib.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
const int STARTING_FPS = 60;

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - delta time");

  int currentFps = STARTING_FPS;

  // initial point of both circles
  Vector2 deltaCircle = {0, (float)SCREEN_HEIGHT / 3.0f};
  Vector2 frameCircle = {0, (float)SCREEN_HEIGHT * (2.0f / 3.0f)};

  const float speed = 10.0f;
  const float circleRadius = 32.0f;

  SetTargetFPS(currentFps);

  SetExitKey(KEY_NULL);

  while (!WindowShouldClose()) {
    float mouseWheel = GetMouseWheelMove();
    if (mouseWheel != 0) {
      currentFps += (int)mouseWheel;
      if (currentFps < 0)
        currentFps = 0;
      SetTargetFPS(currentFps);
    }

    deltaCircle.x += GetFrameTime() * 6.0f * speed;
    frameCircle.x += 0.1f * speed;

    if (deltaCircle.x > SCREEN_WIDTH)
      deltaCircle.x = 0;
    if (frameCircle.x > SCREEN_WIDTH)
      frameCircle.x = 0;

    if (IsKeyPressed(KEY_R)) {
      deltaCircle.x = 0;
      frameCircle.x = 0;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the circles
    DrawCircleV(deltaCircle, circleRadius, RED);
    DrawCircleV(frameCircle, circleRadius, BLUE);

    const char *fpsText = 0;
    if (currentFps <= 0)
      fpsText = TextFormat("FPS: unlimited (%i)", GetFPS());
    else
      fpsText = TextFormat("FPS: %i (target: %i)", GetFPS(), currentFps);

    DrawText(fpsText, 10, 10, 20, DARKGRAY);
    DrawText(TextFormat("Frame time: %02.02f ms", GetFrameTime()), 10, 30, 20,
             DARKGRAY);
    DrawText("Use the scroll wheel to chang the fps limit, r to reset", 10, 50,
             20, DARKGRAY);

    DrawText("FUNC: x += GetFrameTime()*speed", 10, 90, 20, RED);
    DrawText("FUNC: x += speed", 10, 240, 20, BLUE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
