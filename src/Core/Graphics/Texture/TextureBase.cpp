#include "TextureBase.h"

TextureBase::TextureBase(GLenum t_tex_type, GLenum t_slot, GLenum t_format, GLenum t_pixel_type): id(0), type(0)
{
}

TextureBase::~TextureBase() = default;

void TextureBase::TexUnit(Shader& t_shader, const char* t_uniform, GLuint t_unit)
{
    GLuint texUni = glGetUniformLocation(t_shader.id, t_uniform);
    t_shader.Activate();
    glUniform1i(texUni, t_unit);
}

void TextureBase::Bind()
{
    glBindTexture(type, id);
}

void TextureBase::Unbind()
{
    glBindTexture(type, 0);
}

void TextureBase::Delete()
{
    glDeleteTextures(1, &id);
}
