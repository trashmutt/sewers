/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // screen init
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose())
  {
    // Update
    
    // Draw
    BeginDrawing();
      ClearBackground(DARKGRAY);
      DrawText("Hello World", 190, 200, 20, BLACK);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
