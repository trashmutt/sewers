#include "sprites.h"
#include "raylib.h"

static const char *sprite_paths[SPRITE_COUNT] = {
    "assets/blob_boi_a_forward.png",
    "assets/tall_boi_a_forward.png",
    "assets/blast_right.png",
};

Sprite sprites[SPRITE_COUNT];

void sprites_load_textures(void) {
  for (int i = 0; i < SPRITE_COUNT; i++) {
    sprites[i].texture = LoadTexture(sprite_paths[i]);
    sprites[i].frame_width = sprites[i].texture.width / FRAMES_MAX;
    sprites[i].frame = (Rectangle){0.0f, 0.0f, sprites[i].frame_width,
                                   sprites[i].texture.height};
  }
}

void sprites_load_starting_projections(int screen_height, int screen_width,
                                       int projection_height,
                                       int projection_width) {
  sprites[SPRITE_BLOB_BOI].projection =
      (Rectangle){0.0f, (float)screen_height - projection_width,
                  projection_width, projection_width};
  sprites[SPRITE_TALL_BOI].projection =
      (Rectangle){(float)screen_width - projection_width,
                  (float)screen_height - projection_width, projection_height,
                  projection_width};
  sprites[SPRITE_BLAST].projection =
      (Rectangle){(float)screen_width - (2 * projection_width),
                  (float)screen_height - projection_width, projection_height,
                  projection_width};
}

void sprites_update_frame(int current_frame) {
  for (int i = 0; i < SPRITE_COUNT; i++) {
    sprites[i].frame.x = current_frame * sprites[i].frame_width;
  }
}

void sprites_draw_all(void) {
  for (int i = 0; i < SPRITE_COUNT; i++) {
    DrawTexturePro(sprites[i].texture, sprites[i].frame, sprites[i].projection,
                   (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
  }
}
