#ifndef RENDER_DATA_CLASS_H
#define RENDER_DATA_CLASS_H

#include "../../Buffers/VAO.h"
#include "../../Graphics/Texture/TextureBase.h"

struct RenderData
{
    RenderData(VAO vao, TextureBase& texture, std::vector<GLuint>& indices)
    {
        this->vao = vao;
        this->texture = &texture;
        this->indices = &indices;
    }
    
    VAO vao;
    TextureBase* texture;
    std::vector<GLuint>* indices;
};

#endif