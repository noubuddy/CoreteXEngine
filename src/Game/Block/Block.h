#ifndef BLOCK_CLASS_H
#define BLOCK_CLASS_H

#include <vector>
#include "../../Core/Graphics/Texture/Texture.h"
#include "glm/vec3.hpp"
#include "../../Core/Graphics/Render/Helpers/Vertices.h"
#include "../../Core/Graphics/Render/Renderer.h"

class Block
{
public:
    Block();
    
    void SetTexture(Texture texture);

    void Spawn(glm::vec3 Position, glm::vec3 Rotation);

private:

    std::vector<GLfloat> *vertices;
    
    void Render();
};

#endif