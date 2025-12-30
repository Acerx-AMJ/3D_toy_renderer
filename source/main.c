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

   while (!WindowShouldClose()) {
      // Update
      const float dt = GetFrameTime();
      
      offset.x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * dt;
      offset.y += (IsKeyDown(KEY_Q) - IsKeyDown(KEY_E)) * dt;
      offset.z += (IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * dt;

      rotation.x += dt * 0.333f;
      rotation.y += dt * 0.333f;
      rotation.z += dt * 0.333f;

      if (IsKeyPressed(KEY_R)) {
         rotation = offset = (Vector3){0.0f, 0.0f, 0.0f};
      }

      if (IsKeyPressed(KEY_F)) {
         getNextShape(&data);
      }

      // Render
      BeginDrawing();
         ClearBackground(BACKGROUND_COLOR);

         // Draw the object
         for (int i = 0; i < data.verticeCount; ++i) {
            Vector3 rotated = rotate(Vector3Add(data.vertices[i], offset), Vector3Add(data.origin, offset), rotation);
            Vector2 translated = translateToScreen(rotated);

            data.points[i] = translated;
            DrawCircleV(translated, 15.0f / rotated.z, FOREGROUND_COLOR);
         }

         for (int i = 0; i < data.lineCount; ++i) {
            Vector2 start = data.points[(int)data.lines[i].x];
            Vector2 end   = data.points[(int)data.lines[i].y];
            DrawLineV(start, end, FOREGROUND_COLOR);
         }

         for (int i = 0; i < data.triangleCount; ++i) {
            Vector2 point1 = data.points[(int)data.triangles[i].x];
            Vector2 point2 = data.points[(int)data.triangles[i].y];
            Vector2 point3 = data.points[(int)data.triangles[i].z];
            DrawTriangle(point1, point2, point3, Fade(FOREGROUND_COLOR, 0.5f));
         }

         // Draw UI
         DrawFPS(5, 5);
         DrawText("WASD EQ to move, R to reset, F to switch models.", 150, 5, 20.0f, FOREGROUND_COLOR);
      EndDrawing();
   }

   ShapeData_free(&data);
   CloseWindow();
   return 0;
}
