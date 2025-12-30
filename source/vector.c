#include "config.h"
#include "vector.h"
#include <math.h>
#include <raymath.h>

// 3D to 2D
Vector2 translateToScreen(Vector3 point) {
   if (point.z == 0.0f) {
      return (Vector2){0.0f, 0.0f}; // How to fix?
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

// Rotate by all 3 axes
Vector3 rotate(Vector3 point, Vector3 origin, Vector3 angles) {
   Vector3 local = Vector3Subtract(point, origin);
   float sx = sinf(angles.x), cx = cosf(angles.x);
   float sy = sinf(angles.y), cy = cosf(angles.y);
   float sz = sinf(angles.z), cz = cosf(angles.z);

   // Rotation around X axis
   float y1 = local.y * cx - local.z * sx;
   float z1 = local.y * sx + local.z * cx;
   local.y = y1;
   local.z = z1;

   // Rotation around Y axis
   float x1 = local.x * cy - local.z * sy;
   float z2 = local.x * sy + local.z * cy;
   local.x = x1;
   local.z = z2;

   // // Rotation around Z axis
   float x2 = local.x * cz - local.y * sz;
   float y2 = local.x * sz + local.y * cz;
   local.x = x2;
   local.y = y2;

   return Vector3Add(local, origin);
}

// Get origin of a model
Vector3 getOrigin(Vector3 *vertices, int verticeCount) {
   float accumulator = 0;

   for (int i = 0; i < verticeCount; ++i) {
      accumulator += vertices[i].z;
   }
   return (Vector3){0.0f, 0.0f, accumulator / verticeCount};
}
