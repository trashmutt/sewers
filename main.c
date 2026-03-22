#include "raylib.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 450;
static const int STARTING_FPS = 60;
static const int EXIT_KEY = KEY_ESCAPE;
static const int MAX_FRAME_SPEED = 15;
static const int MIN_FRAME_SPEED = 1;
static const int FRAME_WIDTH = 32;
static const int PROJECTION_WIDTH = 256;

static int currentFps = STARTING_FPS;

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "up and down game");

  Texture2D blobBoi = LoadTexture("assets/blob_boi_a_forward.png");
  Texture2D tallBoi = LoadTexture("assets/tall_boi_a_forward.png");
  Texture2D blast = LoadTexture("assets/blast_right.png");

  Rectangle blobBoiProjection = {0.0f, (float)SCREEN_HEIGHT - PROJECTION_WIDTH,
                                 PROJECTION_WIDTH, PROJECTION_WIDTH};
  Rectangle tallBoiProjection = {(float)SCREEN_WIDTH - PROJECTION_WIDTH,
                                 (float)SCREEN_HEIGHT - PROJECTION_WIDTH,
                                 PROJECTION_WIDTH, PROJECTION_WIDTH};
  Rectangle blastProjection = {(float)SCREEN_WIDTH - (2 * PROJECTION_WIDTH),
                               (float)SCREEN_HEIGHT - PROJECTION_WIDTH,
                               PROJECTION_WIDTH, PROJECTION_WIDTH};

  Rectangle frameRec = {0.0f, 0.0f, FRAME_WIDTH, FRAME_WIDTH};
  Rectangle blastFrameRec = {0.0f, 0.0f, 16, 16};

  int currentFrame = 0;
  int framesCounter = 0;
  int framesSpeed = 1;
  SetTargetFPS(60);

  SetExitKey(EXIT_KEY);
  while (!WindowShouldClose()) {
    // Update
    framesCounter++;

    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 1)
        currentFrame = 0;

      frameRec.x = currentFrame * FRAME_WIDTH;
      blastFrameRec.x = currentFrame * 16;
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexturePro(blobBoi, frameRec, blobBoiProjection, (Vector2){0.0f, 0.0f},
                   0.0f, WHITE);
    DrawTexturePro(tallBoi, frameRec, tallBoiProjection, (Vector2){0.0f, 0.0f},
                   0.0f, WHITE);

    DrawTexturePro(blast, blastFrameRec, blastProjection, (Vector2){0.0f, 0.0f},
                   0.0f, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
