#ifndef SPRITES_H
#define SPRITES_H

#include "raylib.h"

extern Texture2D sprites[3];

extern const char *sprites_blob_boi_path;
extern const char *sprites_tall_boi_path;
extern const char *sprites_blast_path;

extern Texture2D sprites_blob_boi;
extern Texture2D sprites_tall_boi;
extern Texture2D sprites_blast;

extern Rectangle sprites_blob_boi_projection;
extern Rectangle sprites_tall_boi_projection;
extern Rectangle sprites_blast_projection;
extern Rectangle sprites_frame_16_px;
extern Rectangle sprites_frame_32_px;

extern void sprites_load_textures(void);
extern void sprites_load_starting_projections(int screen_height,
                                              int screen_width,
                                              int sprite_height,
                                              int sprite_width);

#endif
