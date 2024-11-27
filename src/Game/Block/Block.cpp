#include "Block.h"

Block::Block()
{
    this->m_vertices = Vertices::GetVertices();
    this->m_indices = Indices::GetIndices();

    // ApplyTexture();
}

Block::~Block()
{

}

void Block::ApplyTexture()
{
    m_texture_array = new TextureArray(m_textures, GL_TEXTURE_2D_ARRAY, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);   
    // m_texture_array.TexUnit(shader_program, "texArray", 0);
    // m_texture_array.Bind();
}
