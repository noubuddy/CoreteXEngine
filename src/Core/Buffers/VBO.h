#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <vector>
#include <glad/glad.h>

class VBO
{
    GLuint m_id;

public:
    VBO(std::vector<GLfloat> t_vertices);

    void Bind();
    void Unbind();
    void Delete();
};

#endif
