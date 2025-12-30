#ifndef TOY_RENDERER_3D_SHAPES_H
#define TOY_RENDERER_3D_SHAPES_H

#include <raylib.h>

// Cube

// Vertices
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

// Lines
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
   // Front face
   {7, 6, 5},
   {5, 4, 7},

   // Left face
   {3, 7, 4},
   {4, 0, 3},

   // Back face
   {2, 3, 0},
   {0, 1, 2},

   // Right face
   {6, 2, 1},
   {1, 5, 6},

   // Top face
   {4, 5, 1},
   {1, 0, 4},

   // Bottom face
   {3, 2, 6},
   {6, 7, 3},
};

// Triangular Prism

// Vertices
static int triangularPrismVerticeCount = 6;
static Vector3 triangularPrismVertices[] = {
   { 0.5f,  0.5f,  1.0f},
   { 0.5f, -0.5f,  1.0f},
   {-0.5f, -0.5f,  1.0f},
   {-0.5f,  0.5f,  1.0f},
   { 0.0f,  0.5f,  2.0f},
   { 0.0f, -0.5f,  2.0f},
};

// Lines
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
   // Front face
   {2, 1, 0},
   {0, 3, 2},

   // Left face
   {5, 2, 3},
   {3, 4, 5},

   // Right face
   {1, 5, 4},
   {4, 0, 1},

   // Top face
   {0, 4, 3},

   // Bottom face
   {2, 5, 1},
};


#endif
