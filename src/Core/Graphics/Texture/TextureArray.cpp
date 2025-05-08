#include "TextureArray.h"

TextureArray::TextureArray(std::vector<core::String> t_images, GLenum t_tex_type, GLenum t_slot, GLenum t_format, GLenum t_pixel_type) : TextureBase(t_tex_type, t_slot, t_format, t_pixel_type)
{
    type = t_tex_type;
    
    int imgWidth, imgHeight, colorChannelsNumber;
    std::vector<unsigned char*> imagesData;
    stbi_set_flip_vertically_on_load(true);
    
    for (const core::String& path : t_images)
    {
        unsigned char* bytes = stbi_load(path.GetData(), &imgWidth, &imgHeight, &colorChannelsNumber, 4);
        if (bytes != nullptr)
        {
            imagesData.push_back(bytes);
        }
    }
    
    glGenTextures(1, &id);
    glActiveTexture(t_slot);
    glBindTexture(t_tex_type, id);
    glTexImage3D(t_tex_type, 0, GL_RGB, 512, 512, imagesData.size(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

    for (int i = 0; i < 6; i++)
    {
        if (imagesData[i])
        {
            glTexSubImage3D(t_tex_type, 0, 0, 0, i, 512, 512, 1, t_format, t_pixel_type, imagesData[i]);
        }
    }

    glTexParameteri(t_tex_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(t_tex_type, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(t_tex_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(t_tex_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    for (unsigned char* data : imagesData)
    {
        stbi_image_free(data);
    }
    
    glBindTexture(t_tex_type, 0);
}