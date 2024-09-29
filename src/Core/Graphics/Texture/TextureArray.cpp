#include "TextureArray.h"

TextureArray::TextureArray(std::vector<std::string> images, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type) : TextureBase(tex_type, slot, format, pixel_type)
{
    type = tex_type;
    
    int img_width, img_height, color_channels_number;
    std::vector<unsigned char*> images_data;
    stbi_set_flip_vertically_on_load(true);
    
    for (const std::string& path : images)
    {
        unsigned char* bytes = stbi_load(path.c_str(), &img_width, &img_height, &color_channels_number, 4);
        if (bytes != nullptr)
        {
            images_data.push_back(bytes);
        }
    }
    
    glGenTextures(1, &id);
    glActiveTexture(slot);
    glBindTexture(tex_type, id);
    glTexImage3D(tex_type, 0, GL_RGB, 512, 512, images_data.size(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

    for (int i = 0; i < 6; i++)
    {
        if (images_data[i])
        {
            glTexSubImage3D(tex_type, 0, 0, 0, i, 512, 512, 1, format, pixel_type, images_data[i]);
        }
    }

    glTexParameteri(tex_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(tex_type, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(tex_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(tex_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    for (unsigned char* data : images_data)
    {
        stbi_image_free(data);
    }
    
    glBindTexture(tex_type, 0);
}