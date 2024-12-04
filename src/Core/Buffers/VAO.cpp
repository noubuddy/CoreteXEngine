#include "VAO.h"

VAO::VAO()
{
    glGenVertexArrays(1, &m_id);
}

void VAO::LinkAttrib(VBO& t_vbo, GLuint t_layout, GLuint t_num_components, GLenum t_type, GLsizeiptr t_stride, void *t_offset)
{
    t_vbo.Bind();
    glVertexAttribPointer(t_layout, t_num_components, t_type, GL_FALSE, t_stride, t_offset);
    glEnableVertexAttribArray(t_layout);
    t_vbo.Unbind();
}

void VAO::Bind()
{
    glBindVertexArray(m_id);
}

void VAO::Unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &m_id);
}