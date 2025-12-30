#ifndef TOY_RENDERER_3D_SHAPES_H
#define TOY_RENDERER_3D_SHAPES_H

#include <raylib.h>

typedef struct {
   int shapeIndex;
   int verticeCount;
   int lineCount;
   int triangleCount;
   Vector3 *vertices;
   Vector2 *lines;
   Vector3 *triangles;
   Vector2 *points;
   Vector3 origin;
} ShapeData;

ShapeData ShapeData_init();
void ShapeData_free(ShapeData *data);

const char* getCurrentShapesName(ShapeData *data);
void getCurrentShape(ShapeData *data);
void getNextShape(ShapeData *data);

#endif
