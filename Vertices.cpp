#include "Vertices.h"
#include "Vertices.inl"

std::vector<GLfloat> Vertices::GetVertices()
{
    std::vector<GLfloat> FinalVertices;
    
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            FinalVertices.push_back(vertices[i][j]);
        }
    }
    
    return FinalVertices;
}

std::vector<GLfloat> Vertices::GetVerticesBySide(CubeSide Side)
{
    std::vector<GLfloat> FinalVertices;
    
    for (int i = 0; i < 32; ++i)
    {
        FinalVertices.push_back(vertices[Side][i]);
    }
    
    return FinalVertices;
}
