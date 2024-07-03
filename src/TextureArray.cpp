#include "TextureArray.h"

TextureArray::TextureArray(std::vector<std::string> images)
{
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
    glBindTexture(GL_TEXTURE_2D_ARRAY, id);
    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, 512, 512, images_data.size(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

    for (int i = 0; i < 6; i++)
    {
        if (images_data[i])
        {
            glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, 512, 512, 1, GL_RGBA, GL_UNSIGNED_BYTE, images_data[i]);
        }
    }

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    for (unsigned char* data : images_data)
    {
        stbi_image_free(data);
    }
    
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}
