#ifndef TEXTURE_ARRAY_CLASS
#define TEXTURE_ARRAY_CLASS

#include <string>
#include <vector>
#include <glad/glad.h>
#include <stb/stb_image.h>

#include "TextureBase.h"
#include "../Shader/Shader.h"


class TextureArray : public TextureBase
{
public:
    TextureArray() = default;
    TextureArray(std::vector<core::String> t_images, GLenum t_tex_type, GLenum t_slot, GLenum t_format, GLenum t_pixel_type);
};

#endif