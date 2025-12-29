#include "config.h"
#include "vector.h"
#include <math.h>
#include <raymath.h>

// 0..W 0..H -> -1..1 -1..1
Vector2 screen(Vector2 point) {
   return (Vector2){
      ((point.x + 1.0f) / 2.0f) * SCREEN_W,
      (1.0f - ((point.y + 1.0f) / 2.0f)) * SCREEN_H,
   };
}

// 3D to 2D
Vector2 translate(Vector3 point) {
   if (point.z == 0.0f) {
      return (Vector2){0.0f, 0.0f};
   }
   
   return (Vector2){
      point.x / point.z,
      point.y / point.z,
   };
}

// Rotate Y axis
Vector3 rotateXZAroundOrigin(Vector3 point, Vector3 origin, float angle) {
   Vector3 local = Vector3Subtract(point, origin);
   float s = sinf(angle), c = cosf(angle);

   return Vector3Add((Vector3){
      local.x * c - local.z * s,
      local.y,
      local.x * s + local.z * c,
   }, origin);
}
