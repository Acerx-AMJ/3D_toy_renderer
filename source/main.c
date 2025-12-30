#include "config.h"
#include "shapes.h"
#include "vector.h"
#include <raylib.h>
#include <raymath.h>

int main() {
   InitWindow(SCREEN_W, SCREEN_H, TITLE);
   SetTargetFPS(60);

   // Shape data
   ShapeData data = ShapeData_init();
   getCurrentShape(&data);

   Vector3 rotation = {0.0f, 0.0f, 0.0f};
   Vector3 offset   = {0.0f, 0.0f, 0.0f};

   char drawIndeces   = 0;
   char drawVertices  = 1;
   char drawLines     = 1;
   char drawTriangles = 1;
   char drawStats     = 1;

   while (!WindowShouldClose()) {
      // Update
      const float dt = GetFrameTime();
      
      offset.x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * dt;
      offset.y += (IsKeyDown(KEY_Q) - IsKeyDown(KEY_E)) * dt;
      offset.z += (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * dt;

      rotation.x += dt * 0.333f;
      rotation.y += dt * 0.333f;
      rotation.z += dt * 0.333f;

      if (IsKeyPressed(KEY_R))
         rotation = offset = (Vector3){0.0f, 0.0f, 0.0f};

      if (IsKeyPressed(KEY_F))
         getNextShape(&data);

      if (IsKeyPressed(KEY_I))
         drawIndeces = !drawIndeces;

      if (IsKeyPressed(KEY_O))
         drawVertices = !drawVertices;

      if (IsKeyPressed(KEY_L))
         drawLines = !drawLines;
      
      if (IsKeyPressed(KEY_T))
         drawTriangles = !drawTriangles;
      
      if (IsKeyPressed(KEY_H))
         drawStats = !drawStats;

      // Render
      BeginDrawing();
         ClearBackground(BACKGROUND_COLOR);

         // Draw the object
         for (int i = 0; i < data.verticeCount; ++i) {
            Vector3 rotated = rotate(Vector3Add(data.vertices[i], offset), Vector3Add(data.origin, offset), rotation);
            Vector2 translated = translateToScreen(rotated);

            data.points[i] = translated;
            if (drawVertices) {
               DrawCircleV(translated, (rotated.z == 0.0f ? 0.0f : 10.0f / fabsf(rotated.z)), FOREGROUND_COLOR);
            }
         }

         for (int i = 0; i < data.lineCount && drawLines; ++i) {
            Vector2 start = data.points[(int)data.lines[i].x];
            Vector2 end   = data.points[(int)data.lines[i].y];
            DrawLineV(start, end, FOREGROUND_COLOR);
         }

         for (int i = 0; i < data.triangleCount && drawTriangles; ++i) {
            Vector2 point1 = data.points[(int)data.triangles[i].x];
            Vector2 point2 = data.points[(int)data.triangles[i].y];
            Vector2 point3 = data.points[(int)data.triangles[i].z];
            DrawTriangle(point1, point2, point3, Fade(FOREGROUND_COLOR, 0.5f));
         }

         for (int i = 0; i < data.verticeCount && drawIndeces; ++i) {
            DrawText(TextFormat("%d", i), data.points[i].x, data.points[i].y, 25, WHITE);
         }

         // Draw UI
         if (drawStats) {
            DrawText(TextFormat("FPS: %d", GetFPS()), 5, 5, 20, WHITE);
            DrawText(getCurrentShapesName(&data), 5, 30, 20, WHITE);
            
            DrawText(TextFormat("OFFSET X: %.3f", offset.x), 5, 55, 20, WHITE);
            DrawText(TextFormat("OFFSET Y: %.3f", offset.y), 5, 80, 20, WHITE);
            DrawText(TextFormat("OFFSET Z: %.3f", offset.z + data.origin.z), 5, 105, 20, WHITE);

            DrawText(TextFormat("ROTATION X: %.3f", fmodf(rotation.x * (180.0f / PI), 360.0f)), 5, 130, 20, WHITE);
            DrawText(TextFormat("ROTATION Y: %.3f", fmodf(rotation.y * (180.0f / PI), 360.0f)), 5, 155, 20, WHITE);
            DrawText(TextFormat("ROTATION Z: %.3f", fmodf(rotation.z * (180.0f / PI), 360.0f)), 5, 180, 20, WHITE);

            DrawText(TextFormat("VERTICES: %d", data.verticeCount), 5, 205, 20, WHITE);
            DrawText(TextFormat("LINES: %d", data.lineCount), 5, 230, 20, WHITE);
            DrawText(TextFormat("TRIANGLES: %d", data.triangleCount), 5, 255, 20, WHITE);
         }
      EndDrawing();
   }

   ShapeData_free(&data);
   CloseWindow();
   return 0;
}
