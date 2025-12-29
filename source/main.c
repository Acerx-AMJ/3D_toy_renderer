#include "config.h"
#include "vector.h"
#include <raylib.h>

int main() {
   InitWindow(SCREEN_W, SCREEN_H, TITLE);
   SetTargetFPS(60);
   float timer = 0.0f;

   while (!WindowShouldClose()) {
      timer += GetFrameTime();

      BeginDrawing();
         ClearBackground(BLACK);
         DrawCircleV(screen(translate((Vector3){-0.5,  0.5, timer})), 20.0f / timer, GREEN);
         DrawCircleV(screen(translate((Vector3){ 0.5,  0.5, timer})), 20.0f / timer, RED);
         DrawCircleV(screen(translate((Vector3){ 0.5, -0.5, timer})), 20.0f / timer, BLUE);
         DrawCircleV(screen(translate((Vector3){-0.5, -0.5, timer})), 20.0f / timer, YELLOW);
      EndDrawing();
   }
   CloseWindow();
   return 0;
}
