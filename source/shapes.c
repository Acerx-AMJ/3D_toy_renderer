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

// Cylinder

static int cylinderVerticeCount = 40;
static Vector3 cylinderVertices[] = {
   { 0.5000f,  0.5000f,  1.5000f},
   { 0.4755f,  0.5000f,  1.6545f},
   { 0.4045f,  0.5000f,  1.7939f},
   { 0.2939f,  0.5000f,  1.9045f},
   { 0.1545f,  0.5000f,  1.9755f},
   {-0.0000f,  0.5000f,  2.0000f},
   {-0.1545f,  0.5000f,  1.9755f},
   {-0.2939f,  0.5000f,  1.9045f},
   {-0.4045f,  0.5000f,  1.7939f},
   {-0.4755f,  0.5000f,  1.6545f},
   {-0.5000f,  0.5000f,  1.5000f},
   {-0.4755f,  0.5000f,  1.3455f},
   {-0.4045f,  0.5000f,  1.2061f},
   {-0.2939f,  0.5000f,  1.0955f},
   {-0.1545f,  0.5000f,  1.0245f},
   { 0.0000f,  0.5000f,  1.0000f},
   { 0.1545f,  0.5000f,  1.0245f},
   { 0.2939f,  0.5000f,  1.0955f},
   { 0.4045f,  0.5000f,  1.2061f},
   { 0.4755f,  0.5000f,  1.3455f},
   { 0.5000f, -0.5000f,  1.5000f},
   { 0.4755f, -0.5000f,  1.6545f},
   { 0.4045f, -0.5000f,  1.7939f},
   { 0.2939f, -0.5000f,  1.9045f},
   { 0.1545f, -0.5000f,  1.9755f},
   {-0.0000f, -0.5000f,  2.0000f},
   {-0.1545f, -0.5000f,  1.9755f},
   {-0.2939f, -0.5000f,  1.9045f},
   {-0.4045f, -0.5000f,  1.7939f},
   {-0.4755f, -0.5000f,  1.6545f},
   {-0.5000f, -0.5000f,  1.5000f},
   {-0.4755f, -0.5000f,  1.3455f},
   {-0.4045f, -0.5000f,  1.2061f},
   {-0.2939f, -0.5000f,  1.0955f},
   {-0.1545f, -0.5000f,  1.0245f},
   { 0.0000f, -0.5000f,  1.0000f},
   { 0.1545f, -0.5000f,  1.0245f},
   { 0.2939f, -0.5000f,  1.0955f},
   { 0.4045f, -0.5000f,  1.2061f},
   { 0.4755f, -0.5000f,  1.3455f},
};

static int cylinderLineCount = 60;
static Vector2 cylinderLines[] = {
   {0, 1},
   {1, 2},
   {2, 3},
   {3, 4},
   {4, 5},
   {5, 6},
   {6, 7},
   {7, 8},
   {8, 9},
   {9, 10},
   {10, 11},
   {11, 12},
   {12, 13},
   {13, 14},
   {14, 15},
   {15, 16},
   {16, 17},
   {17, 18},
   {18, 19},
   {19, 0},
   {20, 21},
   {21, 22},
   {22, 23},
   {23, 24},
   {24, 25},
   {25, 26},
   {26, 27},
   {27, 28},
   {28, 29},
   {29, 30},
   {30, 31},
   {31, 32},
   {32, 33},
   {33, 34},
   {34, 35},
   {35, 36},
   {36, 37},
   {37, 38},
   {38, 39},
   {39, 20},
   {0, 20},
   {1, 21},
   {2, 22},
   {3, 23},
   {4, 24},
   {5, 25},
   {6, 26},
   {7, 27},
   {8, 28},
   {9, 29},
   {10, 30},
   {11, 31},
   {12, 32},
   {13, 33},
   {14, 34},
   {15, 35},
   {16, 36},
   {17, 37},
   {18, 38},
   {19, 39},
};

static int cylinderTriangleCount = 76;
static Vector3 cylinderTriangles[] = {
   {0, 1, 2},
   {0, 2, 3},
   {0, 3, 4},
   {0, 4, 5},
   {0, 5, 6},
   {0, 6, 7},
   {0, 7, 8},
   {0, 8, 9},
   {0, 9, 10},
   {0, 10, 11},
   {0, 11, 12},
   {0, 12, 13},
   {0, 13, 14},
   {0, 14, 15},
   {0, 15, 16},
   {0, 16, 17},
   {0, 17, 18},
   {0, 18, 19},
   {20, 39, 38},
   {20, 38, 37},
   {20, 37, 36},
   {20, 36, 35},
   {20, 35, 34},
   {20, 34, 33},
   {20, 33, 32},
   {20, 32, 31},
   {20, 31, 30},
   {20, 30, 29},
   {20, 29, 28},
   {20, 28, 27},
   {20, 27, 26},
   {20, 26, 25},
   {20, 25, 24},
   {20, 24, 23},
   {20, 23, 22},
   {20, 22, 21},
   {20, 21, 1},
   {1, 0, 20},
   {21, 22, 2},
   {2, 1, 21},
   {22, 23, 3},
   {3, 2, 22},
   {23, 24, 4},
   {4, 3, 23},
   {24, 25, 5},
   {5, 4, 24},
   {25, 26, 6},
   {6, 5, 25},
   {26, 27, 7},
   {7, 6, 26},
   {27, 28, 8},
   {8, 7, 27},
   {28, 29, 9},
   {9, 8, 28},
   {29, 30, 10},
   {10, 9, 29},
   {30, 31, 11},
   {11, 10, 30},
   {31, 32, 12},
   {12, 11, 31},
   {32, 33, 13},
   {13, 12, 32},
   {33, 34, 14},
   {14, 13, 33},
   {34, 35, 15},
   {15, 14, 34},
   {35, 36, 16},
   {16, 15, 35},
   {36, 37, 17},
   {17, 16, 36},
   {37, 38, 18},
   {18, 17, 37},
   {38, 39, 19},
   {19, 18, 38},
   {39, 20, 0},
   {0, 19, 39},
};

void setShapeToCylinder(ShapeData *data) {
   data->verticeCount = cylinderVerticeCount;
   data->lineCount = cylinderLineCount;
   data->triangleCount = cylinderTriangleCount;

   data->vertices = cylinderVertices;
   data->lines = cylinderLines;
   data->triangles = cylinderTriangles;
}

// Shape functions

typedef void (*shapeFunction)(ShapeData*);

static int shapeCount = 4;
static shapeFunction shapeGetters[] = {
   setShapeToCube,
   setShapeToTriangularPrism,
   setShapeToPyramid,
   setShapeToCylinder,
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
