#ifndef RENDER_DATA_CLASS_H
#define RENDER_DATA_CLASS_H

#include "../../Buffers/VAO.h"
#include "../../Graphics/Texture/Texture.h"

struct RenderData
{
    RenderData(VAO vao, Texture& texture, std::vector<GLuint>& indices)
    {
        this->vao = vao;
        this->texture = &texture;
        this->indices = &indices;
    }
    
    VAO vao;
    Texture* texture;
    std::vector<GLuint>* indices;
};

#endif