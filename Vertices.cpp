#include "Vertices.h"
#include "Vertices.inl"

std::vector<GLfloat> Vertices::GetVertices()
{
    std::vector<GLfloat> FinalVertices;
    
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

std::vector<GLfloat> Vertices::GetVerticesBySide(CubeSide Side)
{
    std::vector<GLfloat> FinalVertices;
    // FinalVertices.reserve(42);
    
    for (int i = 0; i < 32; ++i)
    {
        FinalVertices[i] = vertices[Side][i];
    }
    
    return FinalVertices;
}
