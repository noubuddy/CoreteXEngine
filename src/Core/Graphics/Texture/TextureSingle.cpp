#include "TextureSingle.h"

TextureSingle::TextureSingle(const char* t_image, GLenum t_tex_type, GLenum t_slot, GLenum t_format, GLenum t_pixel_type) : TextureBase(t_tex_type, t_slot, t_format, t_pixel_type)
{
    type = t_tex_type;

    int imgWidth, imgHeight, colorChannelsNumber;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *bytes = stbi_load(t_image, &imgWidth, &imgHeight, &colorChannelsNumber, 0);

    glGenTextures(1, &id);
    glActiveTexture(t_slot);
    glBindTexture(t_tex_type, id);

    glTexParameteri(t_tex_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(t_tex_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(t_tex_type, 0, GL_RGB, imgWidth, imgHeight, 0, t_format, t_pixel_type, bytes);
    glGenerateMipmap(t_tex_type);

    stbi_image_free(bytes);
    glBindTexture(t_tex_type, 0);
}