#include "config.h"
#include "vector.h"
#include <raylib.h>

int main() {
   InitWindow(SCREEN_W, SCREEN_H, TITLE);
   SetTargetFPS(60);

   // Vertices
   int verticeCount = 8;
   Vector3 vertices[] = {
      {-0.5,  0.5,  2.0f},
      { 0.5,  0.5,  2.0f},
      { 0.5, -0.5,  2.0f},
      {-0.5, -0.5,  2.0f},
      {-0.5,  0.5,  1.0f},
      { 0.5,  0.5,  1.0f},
      { 0.5, -0.5,  1.0f},
      {-0.5, -0.5,  1.0f},
   };

   // Translated vertices to screen space
   Vector2 points[verticeCount];

   // Lines
   int lineCount = 12;
   Vector2 lines[] = {
      {0, 1},
      {1, 2},
      {2, 3},
      {3, 0},

      {4, 5},
      {5, 6},
      {6, 7},
      {7, 4},

      {4, 0},
      {5, 1},
      {6, 2},
      {7, 3},
   };

   // Rotation origin
   Vector3 origin = getOrigin(vertices, verticeCount);
   float timer = 0.0f;

   while (!WindowShouldClose()) {
      timer += GetFrameTime();

      BeginDrawing();
         ClearBackground(BACKGROUND_COLOR);

         for (int i = 0; i < verticeCount; ++i) {
            Vector3 rotated = rotateAroundOriginYZ(vertices[i], origin, timer);
            Vector2 translated = translateToScreen(rotated);

            points[i] = translated;
            DrawCircleV(translated, 15.0f / rotated.z, FOREGROUND_COLOR);
         }

         for (int i = 0; i < lineCount; ++i) {
            Vector2 start = points[(int)lines[i].x];
            Vector2 end   = points[(int)lines[i].y];
            DrawLineV(start, end, FOREGROUND_COLOR);
         }
      EndDrawing();
   }
   CloseWindow();
   return 0;
}
