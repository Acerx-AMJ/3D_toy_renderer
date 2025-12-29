#include <raylib.h>

#define SCREEN_W 800
#define SCREEN_H 600

int main() {
   InitWindow(SCREEN_W, SCREEN_H, "3D Toy Renderer");

   while (!WindowShouldClose()) {
      BeginDrawing();
         DrawCircle(SCREEN_W / 2, SCREEN_H / 2, 200, RED);
      EndDrawing();
   }
   CloseWindow();
   return 0;
}
