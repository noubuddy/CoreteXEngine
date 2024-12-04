#include "Vertices.h"
#include "Vertices.inl"

#include <iostream>

std::vector<GLfloat> Vertices::GetVertices()
{
    std::vector<GLfloat> finalVertices;

    CubeSide cubeSide;
    
    for (int i = 0; i < GetFacesAmount(); ++i)
    {
        cubeSide = static_cast<CubeSide>(i);
        
        for (int j = 0; j < GetVerticesAmount(cubeSide); ++j)
        {
            finalVertices.push_back(vertices[i][j]);
        }
    }
    
    return finalVertices;
}

std::vector<GLfloat> Vertices::GetVerticesBySide(CubeSide t_side)
{
    std::vector<GLfloat> finalVertices;
    
    for (int i = 0; i < GetVerticesAmount(t_side); ++i)
    {
        finalVertices.push_back(vertices[t_side][i]);
    }
    
    return finalVertices;
}

int Vertices::GetFacesAmount()
{
    return vertices.size();
}

int Vertices::GetVerticesAmount(CubeSide t_side)
{
    return vertices[t_side].size();
}


