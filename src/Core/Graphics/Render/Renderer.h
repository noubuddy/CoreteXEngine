#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include "../../Data/Structs/RenderData.h"
#include "../../Buffers/EBO.h"

class Renderer
{
public:
    
    void Render();
    
    void PushRenderData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, Texture& texture);

private:

    std::vector<RenderData> mRenderData;
    
};

#endif