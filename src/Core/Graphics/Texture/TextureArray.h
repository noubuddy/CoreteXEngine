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
    TextureArray(std::vector<std::string> images, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type);
};

#endif