#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <vector>
#include <glad/glad.h>

class EBO
{
    GLuint m_id;

public:
    EBO(std::vector<GLuint> t_indices);

    void Bind();
    void Unbind();
    void Delete();
};

#endif
