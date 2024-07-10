#include "Texture.h"

Texture::Texture(const char* image, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type)
{
    type = tex_type;

    int img_width, img_height, color_channels_number;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *bytes = stbi_load(image, &img_width, &img_height, &color_channels_number, 0);

    glGenTextures(1, &id);
    glActiveTexture(slot);
    glBindTexture(tex_type, id);

    glTexParameteri(tex_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(tex_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(tex_type, 0, GL_RGB, img_width, img_height, 0, format, pixel_type, bytes);
    glGenerateMipmap(tex_type);

    stbi_image_free(bytes);
    glBindTexture(tex_type, 0);
}

void Texture::TexUnit(Shader &shader, const char* uniform, GLuint unit)
{
	GLuint tex_uni = glGetUniformLocation(shader.id, uniform);
	shader.Activate();
	glUniform1i(tex_uni, unit);
}

void Texture::Bind()
{
	glBindTexture(type, id);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &id);
}
