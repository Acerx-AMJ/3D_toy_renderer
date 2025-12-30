#include "config.h"
#include "vector.h"
#include <raylib.h>
#include <raymath.h>

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

   int triangleCount = 12;
   Vector3 triangles[] = {
      // Front face
      {7, 6, 5},
      {5, 4, 7},

      // Left face
      {3, 7, 4},
      {4, 0, 3},

      // Back face
      {2, 3, 0},
      {0, 1, 2},

      // Right face
      {6, 2, 1},
      {1, 5, 6},

      // Top face
      {4, 5, 1},
      {1, 0, 4},

      // Bottom face
      {3, 2, 6},
      {6, 7, 3},
   };

   // Rotation origin
   Vector3 origin   = getOrigin(vertices, verticeCount);
   Vector3 rotation = {0.0f, 0.0f, 0.0f};
   Vector3 offset   = {0.0f, 0.0f, 0.0f};

   while (!WindowShouldClose()) {
      const float dt = GetFrameTime();
      
      offset.x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * dt;
      offset.y += (IsKeyDown(KEY_Q) - IsKeyDown(KEY_E)) * dt;
      offset.z += (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * dt;

      rotation.x += dt;
      rotation.y += dt;
      rotation.z += dt;

      BeginDrawing();
         ClearBackground(BACKGROUND_COLOR);

         // Draw the object
         for (int i = 0; i < verticeCount; ++i) {
            Vector3 rotated = rotate(Vector3Add(vertices[i], offset), Vector3Add(origin, offset), rotation);
            Vector2 translated = translateToScreen(rotated);

            points[i] = translated;
            DrawCircleV(translated, 15.0f / rotated.z, FOREGROUND_COLOR);
         }

         for (int i = 0; i < lineCount; ++i) {
            Vector2 start = points[(int)lines[i].x];
            Vector2 end   = points[(int)lines[i].y];
            DrawLineV(start, end, FOREGROUND_COLOR);
         }

         for (int i = 0; i < triangleCount; ++i) {
            Vector2 point1 = points[(int)triangles[i].x];
            Vector2 point2 = points[(int)triangles[i].y];
            Vector2 point3 = points[(int)triangles[i].z];
            DrawTriangle(point1, point2, point3, Fade(FOREGROUND_COLOR, 0.5f));
         }
         DrawFPS(5, 5);
      EndDrawing();
   }
   CloseWindow();
   return 0;
}
