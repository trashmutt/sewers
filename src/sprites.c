#include "sprites.h"
#include "raylib.h"

const char *sprites_blob_boi_path = "assets/blob_boi_a_forward.png";
const char *sprites_tall_boi_path = "assets/tall_boi_a_forward.png";
const char *sprites_blast_path = "assets/blast_right.png";

Texture2D sprites_blob_boi;
Texture2D sprites_tall_boi;
Texture2D sprites_blast;

Rectangle sprites_blob_boi_projection;
Rectangle sprites_tall_boi_projection;
Rectangle sprites_blast_projection;
Rectangle sprites_frame_16_px;
Rectangle sprites_frame_32_px;

void sprites_load_textures(void) {
  sprites_blob_boi = LoadTexture("assets/blob_boi_a_forward.png");
  sprites_tall_boi = LoadTexture("assets/tall_boi_a_forward.png");
  sprites_blast = LoadTexture("assets/blast_right.png");
}

void sprites_load_starting_projections(int screen_height, int screen_width,
                                       int prijection_height,
                                       int projection_width) {
  sprites_frame_16_px = (Rectangle){0.0f, 0.0f, 16, 16};
  sprites_frame_32_px = (Rectangle){0.0f, 0.0f, 32, 32};

  sprites_blob_boi_projection =
      (Rectangle){0.0f, (float)screen_height - projection_width,
                  projection_width, projection_width};
  sprites_tall_boi_projection =
      (Rectangle){(float)screen_width - projection_width,
                  (float)screen_height - projection_width, projection_width,
                  projection_width};
  sprites_blast_projection =
      (Rectangle){(float)screen_width - (2 * projection_width),
                  (float)screen_height - projection_width, projection_width,
                  projection_width};
}
