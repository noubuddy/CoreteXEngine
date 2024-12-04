#ifndef RENDER_DATA_CLASS_H
#define RENDER_DATA_CLASS_H

#include "../../Buffers/VAO.h"
#include "../../Graphics/Texture/TextureBase.h"

struct RenderData
{
    RenderData(VAO t_vao, TextureBase& t_texture, std::vector<GLuint>& t_indices)
    {
        this->vao = t_vao;
        this->texture = &t_texture;
        this->indices = &t_indices;
    }
    
    VAO vao;
    TextureBase* texture;
    std::vector<GLuint>* indices;
};

#endif