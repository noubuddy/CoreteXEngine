#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include "../../Data/Structs/RenderData.h"
#include "../../Buffers/EBO.h"
#include "../Texture/TextureArray.h"

class Renderer
{
public:
    
    void Render();
    
    void PushRenderData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, TextureBase& texture);

    void EnableDepthTest(bool enable);

private:

    std::vector<RenderData> mRenderData;
    
};

#endif