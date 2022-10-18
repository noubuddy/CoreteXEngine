#include "Texture.h"

Texture::Texture(const char* image, GLenum tex_type, GLenum slot, GLenum format, GLenum pixel_type)
{
	// Assigns the type of the texture ot the texture object
    type = tex_type;

	// Stores the width, height, and the number of color channels of the image
    int img_width, img_height, color_channels_number;
	// Flips the image so it appears right side up
    stbi_set_flip_vertically_on_load(true);
	// Reads the image from a file and stores it in bytes
    unsigned char *bytes = stbi_load(image, &img_width, &img_height, &color_channels_number, 0);

	// Generates an OpenGL texture object
    glGenTextures(1, &id);
	// Assigns the texture to a Texture Unit
    glActiveTexture(slot);
    glBindTexture(tex_type, id);

	// Configures the type of algorithm that is used to make the image smaller or bigger
    glTexParameteri(tex_type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(tex_type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Configures the way the texture repeats (if it does at all)
    glTexParameteri(tex_type, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(tex_type, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Extra lines in case you choose to use GL_CLAMP_TO_BORDER
    // float flat_color[] = {1.0f, 1.0f, 1.0f, 1.0f};
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flat_color);

	// Assigns the image to the OpenGL Texture object
    glTexImage2D(tex_type, 0, GL_RGB, img_width, img_height, 0, format, pixel_type, bytes);
	// Generates MipMaps
    glGenerateMipmap(tex_type);

	// Deletes the image data as it is already in the OpenGL Texture object
    stbi_image_free(bytes);
	// Unbinds the OpenGL Texture object so that it can't accidentally be modified
    glBindTexture(tex_type, 0);
}

void Texture::TexUnit(Shader &shader, const char* uniform, GLuint unit)
{
	// Gets the location of the uniform
	GLuint tex_uni = glGetUniformLocation(shader.id, uniform);
	// Shader needs to be activated before changing the value of a uniform
	shader.Activate();
	// Sets the value of the uniform
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
