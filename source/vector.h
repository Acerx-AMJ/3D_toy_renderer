#ifndef TOY_RENDERER_3D_VECTOR_H
#define TOY_RENDERER_3D_VECTOR_H

#include <raylib.h>

Vector2 translateToScreen(Vector3 point);
Vector3 rotateAroundOriginYZ(Vector3 point, Vector3 origin, float angle);
Vector3 rotateAroundOriginXZ(Vector3 point, Vector3 origin, float angle);
Vector3 rotateAroundOriginXY(Vector3 point, Vector3 origin, float angle);
Vector3 rotate(Vector3 point, Vector3 origin, Vector3 angles);

Vector3 getOrigin(Vector3 *vertices, int verticeCount);

#endif
