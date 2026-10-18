#include "config.h"
#include "vector.h"
#include <math.h>
#include <raymath.h>

float triangleNormalZ(Vector2 p1, Vector2 p2, Vector2 p3) {
   float ax = p2.x - p1.x;
   float ay = p2.y - p1.y;
   float bx = p3.x - p1.x;
   float by = p3.y - p1.y;
   return ax * by - ay * bx;
}

// 3D to 2D
Vector2 translateToScreen(Vector3 point) {
   if (point.z <= 0.0f) {
      return (Vector2){0.0f, 0.0f}; // How to fix?
   }
   
   Vector2 coords = {
      point.x / point.z,
      point.y / point.z,
   };

   return (Vector2){
      ((coords.x + 1.0f) / 2.0f) * SCREEN_W,
      (1.0f - ((coords.y + 1.0f) / 2.0f)) * SCREEN_H,
   };
}

// Rotate by all 3 axes
Vector3 rotate(Vector3 point, Vector3 angles) {
   Vector3 result = point;
   float sx = sinf(angles.x), cx = cosf(angles.x);
   float sy = sinf(angles.y), cy = cosf(angles.y);
   float sz = sinf(angles.z), cz = cosf(angles.z);

   // Rotation around Y axis
   float x1 = result.x * cy - result.z * sy;
   float z2 = result.x * sy + result.z * cy;
   result.x = x1;
   result.z = z2;

   // Rotation around X axis
   float y1 = result.y * cx - result.z * sx;
   float z1 = result.y * sx + result.z * cx;
   result.y = y1;
   result.z = z1;

   // // Rotation around Z axis
   float x2 = result.x * cz - result.y * sz;
   float y2 = result.x * sz + result.y * cz;
   result.x = x2;
   result.y = y2;

   return result;
}
