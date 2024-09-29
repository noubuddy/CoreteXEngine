#ifndef BLOCK_TYPES_CLASS
#define BLOCK_TYPES_CLASS

#include "../../Core/Graphics/Texture/TextureSingle.h"

namespace BLOCK_TYPE
{
    enum BlockType
    {
        GRASS,
        SAND,
        WATER
    };
}


inline void SetBlockType(BLOCK_TYPE::BlockType BlockType, Shader ShaderProgram)
{
    switch (BlockType)
    {
    case BLOCK_TYPE::GRASS:
        {
            TextureSingle texture("block-top.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
            texture.TexUnit(ShaderProgram, "tex0", 0);
            texture.Bind();
        }
        break;

    case BLOCK_TYPE::SAND:
        {
            TextureSingle texture("sand.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
            texture.TexUnit(ShaderProgram, "tex0", 0);
            texture.Bind();
        }
        break;

    case BLOCK_TYPE::WATER:
        {
            TextureSingle texture("water.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
            texture.TexUnit(ShaderProgram, "tex0", 0);
            texture.Bind();
        }
        break;
    }
}

#endif
