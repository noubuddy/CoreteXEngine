#ifndef BLOCK_CLASS_H
#define BLOCK_CLASS_H

#include <vector>
#include "glm/vec3.hpp"
#include "../../Core/Graphics/Render/Helpers/Vertices.h"
#include "../../Core/Graphics/Render/Helpers/Indices.h"
#include "../../Core/GameObjects/ObjectBase.h"
#include "../../Core/Graphics/Texture/TextureArray.h"

class Block : public ObjectBase
{
public:
    Block();
    ~Block();

private:

    void ApplyTexture();
    
    std::vector<GLfloat> m_vertices;
    std::vector<GLuint> m_indices;
    std::vector<std::string> m_textures =
    {
        "resources/block.jpg", "resources/block.jpg", "resources/block.jpg",
        "resources/block.jpg", "resources/block-top.jpg", "resources/block.jpg"
    };

    TextureArray* m_texture_array;
    Shader* m_shader_program;

    
};

#endif