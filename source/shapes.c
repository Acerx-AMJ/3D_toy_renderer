#include "shapes.h"
#include <stdlib.h>

// Shape data functions

ShapeData ShapeData_init() {
   ShapeData data;
   data.verticeCount = 0;
   data.lineCount = 0;
   data.triangleCount = 0;
   data.vertices = NULL;
   data.lines = NULL;
   data.triangles = NULL;
   data.points = NULL;
   data.origin = (Vector3){0.0f, 0.0f, 0.0f};
   return data;
}

void ShapeData_free(ShapeData *data) {
   if (data->points) {
      free(data->points);
   }
}

// Cube

static int cubeVerticeCount = 8;
static Vector3 cubeVertices[] = {
   {-0.5f,  0.5f,  2.0f},
   { 0.5f,  0.5f,  2.0f},
   { 0.5f, -0.5f,  2.0f},
   {-0.5f, -0.5f,  2.0f},
   {-0.5f,  0.5f,  1.0f},
   { 0.5f,  0.5f,  1.0f},
   { 0.5f, -0.5f,  1.0f},
   {-0.5f, -0.5f,  1.0f},
};

static int cubeLineCount = 12;
static Vector2 cubeLines[] = {
   {0, 1},
   {1, 2},
   {2, 3},
   {3, 0},
   {4, 5},
   {5, 6},
   {6, 7},
   {7, 4},
   {4, 0},
   {5, 1},
   {6, 2},
   {7, 3},
};

static int cubeTriangleCount = 12;
static Vector3 cubeTriangles[] = {
   {7, 6, 5},
   {5, 4, 7},
   {3, 7, 4},
   {4, 0, 3},
   {2, 3, 0},
   {0, 1, 2},
   {6, 2, 1},
   {1, 5, 6},
   {4, 5, 1},
   {1, 0, 4},
   {3, 2, 6},
   {6, 7, 3},
};

void setShapeToCube(ShapeData *data) {
   data->verticeCount = cubeVerticeCount;
   data->lineCount = cubeLineCount;
   data->triangleCount = cubeTriangleCount;

   data->vertices = cubeVertices;
   data->lines = cubeLines;
   data->triangles = cubeTriangles;
}
// Triangular Prism

static int triangularPrismVerticeCount = 6;
static Vector3 triangularPrismVertices[] = {
   { 0.5f,  0.5f,  1.0f},
   { 0.5f, -0.5f,  1.0f},
   {-0.5f, -0.5f,  1.0f},
   {-0.5f,  0.5f,  1.0f},
   { 0.0f,  0.5f,  2.0f},
   { 0.0f, -0.5f,  2.0f},
};

static int triangularPrismLineCount = 9;
static Vector2 triangularPrismLines[] = {
   {0, 1},
   {1, 2},
   {2, 3},
   {3, 0},
   {4, 5},
   {3, 4},
   {0, 4},
   {2, 5},
   {1, 5},
};

static int triangularPrismTriangleCount = 8;
static Vector3 triangularPrismTriangles[] = {
   {2, 1, 0},
   {0, 3, 2},
   {5, 2, 3},
   {3, 4, 5},
   {1, 5, 4},
   {4, 0, 1},
   {0, 4, 3},
   {2, 5, 1},
};

void setShapeToTriangularPrism(ShapeData *data) {
   data->verticeCount = triangularPrismVerticeCount;
   data->lineCount = triangularPrismLineCount;
   data->triangleCount = triangularPrismTriangleCount;

   data->vertices = triangularPrismVertices;
   data->lines = triangularPrismLines;
   data->triangles = triangularPrismTriangles;
}
// Pyramid

static int pyramidVerticeCount = 5;
static Vector3 pyramidVertices[] = {
   { 0.5f, -0.5f,  1.0f},
   {-0.5f, -0.5f,  1.0f},
   { 0.0f,  0.5f,  1.5f},
   { 0.5f, -0.5f,  2.0f},
   {-0.5f, -0.5f,  2.0f},
};

static int pyramidLineCount = 8;
static Vector2 pyramidLines[] = {
   {0, 1},
   {1, 4},
   {4, 3},
   {3, 0},
   {0, 2},
   {1, 2},
   {4, 2},
   {3, 2},
};

static int pyramidTriangleCount = 6;
static Vector3 pyramidTriangles[] = {
   {3, 2, 0},
   {0, 2, 1},
   {1, 2, 4},
   {4, 2, 3},
   {3, 0, 1},
   {1, 4, 3},
};

void setShapeToPyramid(ShapeData *data) {
   data->verticeCount = pyramidVerticeCount;
   data->lineCount = pyramidLineCount;
   data->triangleCount = pyramidTriangleCount;

   data->vertices = pyramidVertices;
   data->lines = pyramidLines;
   data->triangles = pyramidTriangles;
}

// Shape functions

typedef void (*shapeFunction)(ShapeData*);

static int shapeCount = 3;
static shapeFunction shapeGetters[] = {
   setShapeToCube,
   setShapeToTriangularPrism,
   setShapeToPyramid,
};

void getCurrentShape(ShapeData *data) {
   ShapeData_free(data);
   shapeGetters[data->shapeIndex](data);

   // Calculate the origin
   float accumulator = 0;
   for (int i = 0; i < data->verticeCount; ++i) {
      accumulator += data->vertices[i].z;
   }
   data->origin = (Vector3){0.0f, 0.0f, accumulator / data->verticeCount};

   // Allocate the memory for points
   data->points = malloc(data->verticeCount * sizeof(Vector2));
}

void getNextShape(ShapeData *data) {
   data->shapeIndex = (data->shapeIndex + 1) % shapeCount;
   getCurrentShape(data);
}
