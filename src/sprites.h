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

extern void sprites_loadTextures(void);

#endif
