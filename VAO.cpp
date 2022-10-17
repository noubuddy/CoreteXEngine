﻿#include "VAO.h"

VAO::VAO()
{
    glGenVertexArrays(1, &id);
}

void VAO::LinkVBO(VBO& vbo, GLuint layout)
{
    vbo.Bind();
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(layout);
    vbo.Unbind();
}

void VAO::Bind()
{
    glBindVertexArray(id);
}

void VAO::Unbind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &id);
}