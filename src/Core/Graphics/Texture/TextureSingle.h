#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>
#include "TextureBase.h"
#include "../../Data/String.h"

class TextureSingle : public TextureBase
{
public:
    TextureSingle(core::String& t_image, GLenum t_tex_type, GLenum t_slot, GLenum t_format, GLenum t_pixel_type);
};

#endif