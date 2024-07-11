#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <vector>
#include <glad/glad.h>

class EBO
{
private:
    GLuint id;

public:
    EBO(std::vector<GLuint> indices);

    void Bind();
    void Unbind();
    void Delete();
};

#endif
