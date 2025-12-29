#ifndef TOY_RENDERER_3D_VECTOR_H
#define TOY_RENDERER_3D_VECTOR_H

#include <raylib.h>

Vector2 screen(Vector2 point);
Vector2 translate(Vector3 point);
Vector3 rotateXZAroundOrigin(Vector3 point, Vector3 origin, float angle);

#endif
