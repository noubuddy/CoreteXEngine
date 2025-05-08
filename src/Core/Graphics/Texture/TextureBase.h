#ifndef TEXTURE_BASE_CLASS_H
#define TEXTURE_BASE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "../Shader/Shader.h"
#include "../../Data/String.h"

class TextureBase
{
public:
    TextureBase() = default;
    TextureBase(GLenum t_tex_type, GLenum t_slot, GLenum t_format, GLenum t_pixel_type);
    virtual ~TextureBase();

    void TexUnit(Shader& t_shader, core::String t_uniform, GLuint t_unit);
    void Bind();
    void Unbind();
    void Delete();

    GLuint id;
    GLenum type;

};

#endif