#include "Renderer.h"

void Renderer::Render()
{
    // TODO: Rewrite renderer to operate with different types of textures (SINGLE/ARRAY)
    for (auto RenderData : mRenderData)
    {
        RenderData.vao.Bind();
        // if (RenderData.texture)
        // {
        //     RenderData.texture->Bind();
        // }
            
        glDrawElements(GL_TRIANGLES, (GLsizei) RenderData.indices->size(), GL_UNSIGNED_INT, nullptr);
        
        RenderData.vao.Unbind();
        // if (RenderData.texture)
        // {
        //     RenderData.texture->Unbind();
        // }
    }
}

void Renderer::PushRenderData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, TextureBase& texture)
{
    VAO vao;
    vao.Bind();

    VBO vbo(vertices);
    EBO ebo(indices);

    // vertex position
    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), nullptr);
    // color
    vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    // texture coordinates
    vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(6 * sizeof(float)));
    // texture index
    vao.LinkAttrib(vbo, 3, 1, GL_FLOAT, 9 * sizeof(float), (void*)(8 * sizeof(float)));

    mRenderData.push_back(RenderData(vao, texture, indices));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();
}

void Renderer::EnableDepthTest(bool enable)
{
    if (enable)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }
}
