#include "config.h"
#include "vector.h"

// 0..W 0..H -> -1..1 -1..1
Vector2 screen(Vector2 point) {
   return (Vector2){
      ((point.x + 1.0f) / 2.0f) * SCREEN_W,
      (1.0f - ((point.y + 1.0f) / 2.0f)) * SCREEN_H,
   };
}

Vector2 translate(Vector3 point) {
   if (point.z == 0.0f) {
      return (Vector2){0.0f, 0.0f};
   }
   
   return (Vector2){
      point.x / point.z,
      point.y / point.z,
   };
}
