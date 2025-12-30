#ifndef TOY_RENDERER_3D_VECTOR_H
#define TOY_RENDERER_3D_VECTOR_H

#include <raylib.h>

Vector2 translateToScreen(Vector3 point);
Vector3 rotate(Vector3 point, Vector3 origin, Vector3 angles);
Vector3 getOrigin(Vector3 *vertices, int verticeCount);

#endif
