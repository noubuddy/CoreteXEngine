#include "DrawCubesRenderPass.h"

void DrawCubesRenderPass::Initialize()
{
    m_vertex_attribute_object.Init();
    m_shader_program = Shader("src/Core/Graphics/Shader/Shaders/default.vert", "src/Core/Graphics/Shader/Shaders/default.frag");

    std::vector<core::String> imagePaths =
    {
        "resources/block.jpg", "resources/block.jpg", "resources/block.jpg",
        "resources/block.jpg", "resources/block-top.jpg", "resources/block.jpg"
    };

    // m_shader_program.Activate();

    m_texture_array = TextureArray(imagePaths, GL_TEXTURE_2D_ARRAY, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    m_texture_array.TexUnit(m_shader_program, "texArray", 0);
    // m_texture_array.Bind();

    std::vector<GLfloat> vertices = Vertices::GetVertices();
    std::vector<GLuint> indices = Indices::GetIndices();

    m_vertex_attribute_object.Bind();

    m_vertex_buffer = VBO(vertices);
    m_element_buffer = EBO(indices);

    m_vertex_attribute_object.LinkAttrib(m_vertex_buffer, 0, 3, GL_FLOAT, 9 * sizeof(float), nullptr);
    m_vertex_attribute_object.LinkAttrib(m_vertex_buffer, 1, 3, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
    m_vertex_attribute_object.LinkAttrib(m_vertex_buffer, 2, 2, GL_FLOAT, 9 * sizeof(float), (void*)(6 * sizeof(float)));
    m_vertex_attribute_object.LinkAttrib(m_vertex_buffer, 3, 1, GL_FLOAT, 9 * sizeof(float), (void*)(8 * sizeof(float)));

    m_vertex_attribute_object.Unbind();
    m_vertex_buffer.Unbind();
    m_element_buffer.Unbind();
}

void DrawCubesRenderPass::Draw(std::vector<CubeAttribs>& t_cubes_draw_commands, Camera& t_camera)
{
    if (t_cubes_draw_commands.empty())
        return;

    for (auto& drawCommand : t_cubes_draw_commands)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(glm::mat4(1.0f), drawCommand.position.ToVec3());
        t_camera.Matrix(80.f, 0.1f, 300.0f, m_shader_program, "camMatrix", model);

        m_vertex_attribute_object.Bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
        m_vertex_attribute_object.Unbind();
    }
}
