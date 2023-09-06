#include "Indices.h"
#include "Indices.inl"

std::vector<GLuint> Indices::GetIndices()
{
    std::vector<GLuint> FinalIndices;
    
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            FinalIndices.push_back(indices[i][j]);
        }
    }
    
    return FinalIndices;
}

std::vector<GLuint> Indices::GetIndicesOfSide()
{
    std::vector<GLuint> FinalIndices;
    
    for (int i = 0; i < 6; ++i)
    {
        FinalIndices.push_back(indices[0][i]);
    }
    
    return FinalIndices;
}
