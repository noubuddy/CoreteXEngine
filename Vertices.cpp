#include "Vertices.h"
#include "Vertices.inl"

#include <iostream>

std::vector<GLfloat> Vertices::GetVertices()
{
    std::vector<GLfloat> FinalVertices;

    CubeSide cube_site;
    
    for (int i = 0; i < GetFacesAmount(); ++i)
    {
        cube_site = static_cast<CubeSide>(i);
        
        for (int j = 0; j < GetVerticesAmount(cube_site); ++j)
        {
            FinalVertices.push_back(vertices[i][j]);
        }
    }
    
    return FinalVertices;
}

std::vector<GLfloat> Vertices::GetVerticesBySide(CubeSide Side)
{
    std::vector<GLfloat> FinalVertices;
    
    for (int i = 0; i < GetVerticesAmount(Side); ++i)
    {
        FinalVertices.push_back(vertices[Side][i]);
    }
    
    return FinalVertices;
}

int Vertices::GetFacesAmount()
{
    return vertices.size();
}

int Vertices::GetVerticesAmount(CubeSide Side)
{
    return vertices[Side].size();
}


