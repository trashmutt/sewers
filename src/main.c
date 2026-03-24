#include "raylib.h"
#include "sprites.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 450;
static const int STARTING_FPS = 60;
static const int EXIT_KEY = KEY_ESCAPE;
static const int MAX_FRAME_SPEED = 15;
static const int MIN_FRAME_SPEED = 1;
static const int FRAME_WIDTH = 32;
static const int PROJECTION_WIDTH = 256;

static int current_fps = STARTING_FPS;

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "up and down game");
  sprites_loadTextures();

  Rectangle blob_boi_projection = {0.0f,
                                   (float)SCREEN_HEIGHT - PROJECTION_WIDTH,
                                   PROJECTION_WIDTH, PROJECTION_WIDTH};
  Rectangle tall_boi_projection = {(float)SCREEN_WIDTH - PROJECTION_WIDTH,
                                   (float)SCREEN_HEIGHT - PROJECTION_WIDTH,
                                   PROJECTION_WIDTH, PROJECTION_WIDTH};
  Rectangle blast_projection = {(float)SCREEN_WIDTH - (2 * PROJECTION_WIDTH),
                                (float)SCREEN_HEIGHT - PROJECTION_WIDTH,
                                PROJECTION_WIDTH, PROJECTION_WIDTH};

  Rectangle frame_rec = {0.0f, 0.0f, FRAME_WIDTH, FRAME_WIDTH};
  Rectangle blast_frame_rec = {0.0f, 0.0f, 16, 16};

  int current_frame = 0;
  int frames_counter = 0;
  int frames_speed = 1;
  SetTargetFPS(60);

  SetExitKey(EXIT_KEY);
  while (!WindowShouldClose()) {
    // Update
    frames_counter++;

    if (frames_counter >= (60 / frames_speed)) {
      frames_counter = 0;
      current_frame++;

      if (current_frame > 1)
        current_frame = 0;

      frame_rec.x = current_frame * FRAME_WIDTH;
      blast_frame_rec.x = current_frame * 16;
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexturePro(sprites_blob_boi, frame_rec, blob_boi_projection,
                   (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
    DrawTexturePro(sprites_tall_boi, frame_rec, tall_boi_projection,
                   (Vector2){0.0f, 0.0f}, 0.0f, WHITE);

    DrawTexturePro(sprites_blast, blast_frame_rec, blast_projection,
                   (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
