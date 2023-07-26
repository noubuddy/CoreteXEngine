#include "Vertices.h"
#include "Vertices.inl"

GLfloat* Vertices::GetVertices(int& VerticesAmount)
{
    VerticesAmount = 0;
    
    if (sizeof vertices != 0)
    {
        VerticesAmount = sizeof vertices / sizeof vertices[0];
    }
    
    return vertices;
}