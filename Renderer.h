#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include "EBO.h"
#include "Texture.h"
#include "VAO.h"

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

class Renderer
{
public:
    
    void Render();
    
    void PushRenderData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, Texture& texture);

private:

    std::vector<RenderData> mRenderData;
    
};

#endif