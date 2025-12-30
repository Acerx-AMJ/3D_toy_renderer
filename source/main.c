#include "config.h"
#include "shapes.h"
#include "vector.h"
#include <raylib.h>
#include <raymath.h>

int main() {
   InitWindow(SCREEN_W, SCREEN_H, TITLE);
   SetTargetFPS(60);

   // Shape data
   int verticeCount = triangularPrismVerticeCount;
   int lineCount = triangularPrismLineCount;
   int triangleCount = triangularPrismTriangleCount;
   Vector3 *vertices = triangularPrismVertices;
   Vector2 *lines = triangularPrismLines;
   Vector3 *triangles = triangularPrismTriangles;

   // Positioning, rotation, etc.
   Vector2 points[verticeCount];

   Vector3 origin   = getOrigin(vertices, verticeCount);
   Vector3 rotation = {0.0f, 0.0f, 0.0f};
   Vector3 offset   = {0.0f, 0.0f, 0.0f};

   while (!WindowShouldClose()) {
      const float dt = GetFrameTime();
      
      offset.x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * dt;
      offset.y += (IsKeyDown(KEY_Q) - IsKeyDown(KEY_E)) * dt;
      offset.z += (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * dt;

      rotation.x += dt * 0.333f;
      rotation.y += dt * 0.333f;
      rotation.z += dt * 0.333f;

      BeginDrawing();
         ClearBackground(BACKGROUND_COLOR);

         // Draw the object
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

         for (int i = 0; i < verticeCount; ++i) {
            Vector3 rotated = rotate(Vector3Add(vertices[i], offset), Vector3Add(origin, offset), rotation);
            Vector2 translated = translateToScreen(rotated);

            points[i] = translated;
            DrawCircleV(translated, 15.0f / rotated.z, FOREGROUND_COLOR);
         }
         DrawFPS(5, 5);
      EndDrawing();
   }
   CloseWindow();
   return 0;
}
