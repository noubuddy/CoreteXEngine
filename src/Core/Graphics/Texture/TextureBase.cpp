#include "TextureBase.h"

TextureBase::TextureBase(GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type): id(0), type(0)
{
}

TextureBase::~TextureBase() = default;

void TextureBase::TexUnit(Shader& shader, const char* uniform, GLuint unit)
{
    GLuint tex_uni = glGetUniformLocation(shader.id, uniform);
    shader.Activate();
    glUniform1i(tex_uni, unit);
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
