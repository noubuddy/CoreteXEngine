#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include<glad/glad.h>
#include"VBO.h"

class VAO
{
    GLuint m_id;

public:
    VAO();

    void LinkAttrib(VBO& t_vbo, GLuint t_layout, GLuint t_num_components, GLenum t_type, GLsizeiptr t_stride, void* t_offset);
    void Bind();
    void Unbind();
    void Delete();
};
#endif
