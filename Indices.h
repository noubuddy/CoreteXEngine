#ifndef INDICES_CLASS_H
#define INDICES_CLASS_H

#include <vector>
#include <glad/glad.h>

class Indices
{
public:

    static std::vector<GLuint> GetIndices();

    static std::vector<GLuint> GetIndicesOfSide();
    
};

#endif