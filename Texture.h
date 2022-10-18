﻿#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.h"

class Texture
{
public:
    GLuint id;
    GLenum type;
    Texture(const char *image, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type);

    // Assigns a texture unit to a texture
    void TexUnit(Shader &shader, const char *uniform, GLuint unit);
    // Binds a texture
    void Bind();
    // Unbinds a texture
    void Unbind();
    // Deletes a texture
    void Delete();
};

#endif