#include "sprites.h"
#include "raylib.h"

const char *sprites_blob_boi_path = "assets/blob_boi_a_forward.png";
const char *sprites_tall_boi_path = "assets/tall_boi_a_forward.png";
const char *sprites_blast_path = "assets/blast_right.png";

Texture2D sprites_blob_boi;
Texture2D sprites_tall_boi;
Texture2D sprites_blast;

void sprites_loadTextures(void) {
  sprites_blob_boi = LoadTexture("assets/blob_boi_a_forward.png");
  sprites_tall_boi = LoadTexture("assets/tall_boi_a_forward.png");
  sprites_blast = LoadTexture("assets/blast_right.png");
}
