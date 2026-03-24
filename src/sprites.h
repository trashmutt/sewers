#ifndef SPRITES_H
#define SPRITES_H

#include "raylib.h"

#define SPRITE_COUNT 3
#define FRAMES_MAX 2

typedef enum {
  SPRITE_BLOB_BOI = 0,
  SPRITE_TALL_BOI = 1,
  SPRITE_BLAST = 2,
} SpriteID;

typedef struct {
  Texture2D texture;
  Rectangle frame;
  Rectangle projection;
  int frame_width;
} Sprite;

extern Sprite sprites[SPRITE_COUNT];

void sprites_load_textures(void);
void sprites_load_starting_projections(int screen_height, int screen_width,
                                       int projection_height,
                                       int projection_width);
void sprites_update_frame(int current_frame);
void sprites_draw_all(void);
#endif
