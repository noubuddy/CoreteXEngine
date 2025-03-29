#include "Renderer.h"

void Renderer::Render()
{
    // TODO: Rewrite renderer to operate with different types of textures (SINGLE/ARRAY)
    for (auto RenderData : m_render_data)
    {
        RenderData.vao.Bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
        RenderData.vao.Unbind();
    }
}

void Renderer::PushRenderData(std::vector<GLfloat>& t_vertices, std::vector<GLuint>& t_indices, TextureBase& t_texture)
{
    VAO vao;
    vao.Bind();

    VBO vbo(t_vertices);
    EBO ebo(t_indices);

    // vertex position
    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), nullptr);
    // color
    vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    // texture coordinates
    vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(6 * sizeof(float)));
    // texture index
    vao.LinkAttrib(vbo, 3, 1, GL_FLOAT, 9 * sizeof(float), (void*)(8 * sizeof(float)));

    m_render_data.push_back(RenderData(vao, t_texture, t_indices));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();
}

void Renderer::EnableDepthTest(bool t_enable)
{
    if (t_enable)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }
}

void Renderer::SetVSyncFreq(unsigned short t_frequency)
{
    glfwSwapInterval(t_frequency);
}
