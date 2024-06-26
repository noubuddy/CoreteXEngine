#include "Renderer.h"

void Renderer::Render()
{
    for (auto RenderData : mRenderData)
    {
        RenderData.vao.Bind();
        // RenderData.texture->Bind();
        
        glDrawElements(GL_TRIANGLES, (GLsizei) RenderData.indices->size(), GL_UNSIGNED_INT, nullptr);
        
        RenderData.vao.Unbind();
        // RenderData.texture->Unbind();
    }
}

void Renderer::PushRenderData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, Texture& texture)
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
