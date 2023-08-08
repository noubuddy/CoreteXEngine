#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <vector>
#include<glad/glad.h>

class VBO
{
public:
    GLuint id;
    VBO(std::vector<GLfloat> vertices);

    void Bind();
    void Unbind();
    void Delete();
};

#endif