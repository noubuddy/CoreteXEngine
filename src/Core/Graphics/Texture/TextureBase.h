#ifndef TEXTURE_BASE_CLASS_H
#define TEXTURE_BASE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "../Shader/Shader.h"

class TextureBase
{
public:
    TextureBase(GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type);
    virtual ~TextureBase();

    void TexUnit(Shader &shader, const char *uniform, GLuint unit);
    void Bind();
    void Unbind();
    void Delete();

    GLuint id;
    GLenum type;

};

#endif