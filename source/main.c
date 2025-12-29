#include "config.h"
#include "vector.h"
#include <raylib.h>

int main() {
   InitWindow(SCREEN_W, SCREEN_H, TITLE);
   SetTargetFPS(60);

   Vector3 origin = {0.0f, 0.0f, 1.5f};
   float timer = 0.0f;

   while (!WindowShouldClose()) {
      timer += GetFrameTime();

      BeginDrawing();
         ClearBackground(BLACK);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){-0.5,  0.5,  2.0f}, origin, timer))), 20.0f, GREEN);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){ 0.5,  0.5,  2.0f}, origin, timer))), 20.0f, RED);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){ 0.5, -0.5,  2.0f}, origin, timer))), 20.0f, BLUE);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){-0.5, -0.5,  2.0f}, origin, timer))), 20.0f, YELLOW);

         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){-0.5,  0.5,  1.0f}, origin, timer))), 20.0f, GREEN);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){ 0.5,  0.5,  1.0f}, origin, timer))), 20.0f, RED);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){ 0.5, -0.5,  1.0f}, origin, timer))), 20.0f, BLUE);
         DrawCircleV(screen(translate(rotateXZAroundOrigin((Vector3){-0.5, -0.5,  1.0f}, origin, timer))), 20.0f, YELLOW);
      EndDrawing();
   }
   CloseWindow();
   return 0;
}
