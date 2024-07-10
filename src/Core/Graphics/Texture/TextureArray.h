#ifndef TEXTURE_ARRAY_CLASS
#define TEXTURE_ARRAY_CLASS
#include <string>
#include <vector>
#include <glad/glad.h>
#include <stb/stb_image.h>


class TextureArray
{
public:

    GLuint id;

    TextureArray(std::vector<std::string> images);
    
};

#endif