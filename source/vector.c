#include "config.h"
#include "vector.h"
#include <math.h>
#include <raymath.h>

// 3D to 2D
Vector2 translateToScreen(Vector3 point) {
   if (point.z == 0.0f) {
      return (Vector2){0.0f, 0.0f};
   }
   
   Vector2 coordinates2D = {
      point.x / point.z,
      point.y / point.z,
   };

   return (Vector2){
      ((coordinates2D.x + 1.0f) / 2.0f) * SCREEN_W,
      (1.0f - ((coordinates2D.y + 1.0f) / 2.0f)) * SCREEN_H,
   };
}

// Rotate X axis
Vector3 rotateAroundOriginYZ(Vector3 point, Vector3 origin, float angle) {
   Vector3 local = Vector3Subtract(point, origin);
   float s = sinf(angle), c = cosf(angle);

   return Vector3Add((Vector3){
      local.x,
      local.z * c - local.y * s,
      local.z * s + local.y * c,
   }, origin);
}

// Rotate Y axis
Vector3 rotateAroundOriginXZ(Vector3 point, Vector3 origin, float angle) {
   Vector3 local = Vector3Subtract(point, origin);
   float s = sinf(angle), c = cosf(angle);

   return Vector3Add((Vector3){
      local.x * c - local.z * s,
      local.y,
      local.x * s + local.z * c,
   }, origin);
}

// Rotate Z axis
Vector3 rotateAroundOriginXY(Vector3 point, Vector3 origin, float angle) {
   Vector3 local = Vector3Subtract(point, origin);
   float s = sinf(angle), c = cosf(angle);

   return Vector3Add((Vector3){
      local.x * c - local.y * s,
      local.x * s + local.y * c,
      local.z,
   }, origin);
}
