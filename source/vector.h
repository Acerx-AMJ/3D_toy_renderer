#ifndef TOY_RENDERER_3D_VECTOR_H
#define TOY_RENDERER_3D_VECTOR_H

#include <raylib.h>

float triangleNormalZ(Vector2 p1, Vector2 p2, Vector2 p3);
Vector2 translateToScreen(Vector3 point);
Vector3 rotate(Vector3 point, Vector3 angles);

#endif
