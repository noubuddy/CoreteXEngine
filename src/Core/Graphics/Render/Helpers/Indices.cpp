#include "Indices.h"
#include "Indices.inl"

std::vector<GLuint> Indices::GetIndices()
{
    std::vector<GLuint> finalIndices;
    
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            finalIndices.push_back(indices[i][j]);
        }
    }
    
    return finalIndices;
}

std::vector<GLuint> Indices::GetIndicesOfSide()
{
    std::vector<GLuint> finalIndices;
    
    for (int i = 0; i < 6; ++i)
    {
        finalIndices.push_back(indices[0][i]);
    }
    
    return finalIndices;
}
