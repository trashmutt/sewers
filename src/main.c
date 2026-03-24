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
  sprites_load_textures();
  sprites_load_starting_projections(SCREEN_HEIGHT, SCREEN_WIDTH,
                                    PROJECTION_WIDTH, PROJECTION_WIDTH);

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

      sprites_frame_32_px.x = current_frame * FRAME_WIDTH;
      sprites_frame_16_px.x = current_frame * 16;
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexturePro(sprites_blob_boi, sprites_frame_32_px,
                   sprites_blob_boi_projection, (Vector2){0.0f, 0.0f}, 0.0f,
                   WHITE);
    DrawTexturePro(sprites_tall_boi, sprites_frame_32_px,
                   sprites_tall_boi_projection, (Vector2){0.0f, 0.0f}, 0.0f,
                   WHITE);

    DrawTexturePro(sprites_blast, sprites_frame_32_px, sprites_blast_projection,
                   (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
