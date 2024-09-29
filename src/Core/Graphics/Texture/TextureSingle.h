#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "TextureBase.h"
#include "../Shader/Shader.h"

class TextureSingle : public TextureBase
{
public:
    TextureSingle(const char *image, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type);
};

#endif