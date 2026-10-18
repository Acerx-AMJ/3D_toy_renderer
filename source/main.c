#include "config.h"
#include "shapes.h"
#include "vector.h"
#include <raylib.h>
#include <raymath.h>

int colorCount = 14;
Color colors[] = {
   GREEN, BLUE, SKYBLUE, MAGENTA, PURPLE, PINK, RED, ORANGE, YELLOW, LIME, WHITE, GRAY, BEIGE, BROWN,
};

const char *colorNames[] = {
   "Green", "Blue", "Skyblue", "Magenta", "Purple", "Pink", "Red", "Orange", "Yellow", "Lime", "White", "Gray", "Beige", "Brown",
};

int main() {
   InitWindow(SCREEN_W, SCREEN_H, TITLE);
   SetTargetFPS(60);

   // Shape data
   ShapeData data = ShapeData_init();
   getCurrentShape(&data);

   Vector3 rotation = {0.0f, 0.0f, 0.0f};
   Vector3 offset   = {0.0f, 0.0f, 0.0f};
   Vector2 lastMousePos = {0.0f, 0.0f};

   int colorIndex = 0;
   Color drawColor = colors[colorIndex];

   char drawIndeces   = 0;
   char drawVertices  = 1;
   char drawLines     = 1;
   char drawTriangles = 1;
   char drawStats     = 1;

   while (!WindowShouldClose()) {
      // Update
      const float dt = GetFrameTime();

      // Update rotation      
      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
         rotation.x = rotation.x - (GetMousePosition().y - lastMousePos.y) * dt;
         rotation.x = fmaxf(-PI / 2, fminf(PI / 2, rotation.x));
         rotation.y = rotation.y + (GetMousePosition().x - lastMousePos.x) * dt;
      }
      lastMousePos = GetMousePosition();

      // Update offset
      Vector3 toffset = {0.0f, 0.0f, 0.0f};
      toffset.x = (IsKeyDown(KEY_A) - IsKeyDown(KEY_D)) * dt;
      toffset.y = (IsKeyDown(KEY_Q) - IsKeyDown(KEY_E)) * dt;
      toffset.z = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * dt;

      if (toffset.x != 0.0f || toffset.y != 0.0f || toffset.z != 0.0f) {
         Vector3 rotatedOffset = rotate(toffset, (Vector3){0, -rotation.y, -rotation.z});
         offset = Vector3Add(offset, rotatedOffset);
      }

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

      if (IsKeyPressed(KEY_C)) {
         colorIndex = (colorIndex + 1) % colorCount;
         drawColor = colors[colorIndex];
      }

      // Render
      BeginDrawing();
         ClearBackground(BLACK);

         // Draw the object
         for (int i = 0; i < data.verticeCount; ++i) {
            Vector3 rotated = rotate(Vector3Add(data.vertices[i], offset), rotation);
            Vector2 translated = translateToScreen(rotated);

            data.points[i] = translated;
            data.zvalues[i] = rotated.z;
            if (drawVertices && (translated.x != 0.0f || translated.y != 0.0f) && rotated.z > 0.0f) {
               DrawCircleV(translated, (rotated.z == 0.0f ? 0.0f : 10.0f / fabsf(rotated.z)), drawColor);
            }
         }

         for (int i = 0; i < data.lineCount && drawLines; ++i) {
            Vector2 line = data.lines[i];
            Vector2 p1 = data.points[(int)line.x];
            Vector2 p2 = data.points[(int)line.y];

            float z1 = data.zvalues[(int)line.x];
            float z2 = data.zvalues[(int)line.y];

            if (z1 > 0.0f && z2 > 0.0f) {
               DrawLineV(p1, p2, drawColor);
            }
         }

         for (int i = 0; i < data.triangleCount && drawTriangles; ++i) {
            Vector3 triangle = data.triangles[i];
            Vector2 p1 = data.points[(int)triangle.x];
            Vector2 p2 = data.points[(int)triangle.y];
            Vector2 p3 = data.points[(int)triangle.z];

            float z1 = data.zvalues[(int)triangle.x];
            float z2 = data.zvalues[(int)triangle.y];
            float z3 = data.zvalues[(int)triangle.z];

            if (z1 > 0.0f && z2 > 0.0f && z3 > 0.0f && triangleNormalZ(p1, p2, p3) <= 0.0f) {
               DrawTriangle(p1, p2, p3, Fade(drawColor, 0.5f));
            }
         }

         for (int i = 0; i < data.verticeCount && drawIndeces; ++i) {
            if (data.zvalues[i] > 0.0f) {
               DrawText(TextFormat("%d", i), data.points[i].x, data.points[i].y, 30.0f / fabsf(data.zvalues[i]), WHITE);
            }
         }

         // Draw UI
         if (drawStats) {
            DrawText(TextFormat("FPS: %d", GetFPS()), 5, 5, 20, WHITE);
            DrawText(TextFormat("SHAPE: %s", getCurrentShapesName(&data)), 5, 30, 20, WHITE);
            DrawText(TextFormat("COLOR: %s", colorNames[colorIndex]), 5, 55, 20, WHITE);

            DrawText(TextFormat("X: %.3f", offset.x), 5, 80, 20, WHITE);
            DrawText(TextFormat("Y: %.3f", offset.y), 5, 105, 20, WHITE);
            DrawText(TextFormat("Z: %.3f", offset.z), 5, 130, 20, WHITE);

            DrawText(TextFormat("ROTATION X: %.3f", fmodf(rotation.x * (180.0f / PI), 360.0f)), 5, 155, 20, WHITE);
            DrawText(TextFormat("ROTATION Y: %.3f", fmodf(rotation.y * (180.0f / PI), 360.0f)), 5, 180, 20, WHITE);
            DrawText(TextFormat("ROTATION Z: %.3f", fmodf(rotation.z * (180.0f / PI), 360.0f)), 5, 205, 20, WHITE);

            DrawText(TextFormat("VERTICES: %d", data.verticeCount), 5, 230, 20, WHITE);
            DrawText(TextFormat("LINES: %d", data.lineCount), 5, 255, 20, WHITE);
            DrawText(TextFormat("TRIANGLES: %d", data.triangleCount), 5, 280, 20, WHITE);
         }
      EndDrawing();
   }

   ShapeData_free(&data);
   CloseWindow();
   return 0;
}
