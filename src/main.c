#include "raylib.h"
#include "sprites.h"

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 450;
static const int PROJECTION_SIZE = 256;
static const int EXIT_KEY = KEY_ESCAPE;

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "up and down game");
  sprites_load_textures();
  sprites_load_starting_projections(SCREEN_HEIGHT, SCREEN_WIDTH,
                                    PROJECTION_SIZE, PROJECTION_SIZE);

  SetTargetFPS(60);
  SetExitKey(EXIT_KEY);

  int current_frame = 0;
  int frames_counter = 0;
  int frames_speed = 1;

  while (!WindowShouldClose()) {
    // Update
    frames_counter++;

    if (frames_counter >= (60 / frames_speed)) {
      frames_counter = 0;
      current_frame = (current_frame + 1) % 2;
      sprites_update_frame(current_frame);
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    sprites_draw_all();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
