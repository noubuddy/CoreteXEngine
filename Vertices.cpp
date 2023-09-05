#include "Vertices.h"
#include "Vertices.inl"

#include <cstdlib>
#include <cstring>

GLfloat* Vertices::GetVertices()
{
    GLfloat* FinalVertices = (GLfloat*) malloc(sizeof(GLfloat) * 192);

    unsigned int Iterator = 0;
    
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            FinalVertices[Iterator] = vertices[i][j];
            Iterator++;
        }
    }
    
    return FinalVertices;
}

GLfloat* Vertices::GetVerticesBySide(CubeSide Side)
{
    GLfloat* FinalVertices = (GLfloat*) malloc(sizeof(GLfloat) * 32);

    for (int i = 0; i < 32; ++i)
    {
        FinalVertices[i] = vertices[Side][i];
    }

    return FinalVertices;
}
