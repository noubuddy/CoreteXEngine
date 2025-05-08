#ifndef DRAW_CUBES_RENDER_PASS_H
#define DRAW_CUBES_RENDER_PASS_H

#include <string>
#include <vector>
#include <glm/vec3.hpp>
#include "../../Texture/TextureArray.h"
#include "../../Render/Helpers/Vertices.h"
#include "../../Render/Helpers/Indices.h"
#include "../../../Buffers/VAO.h"
#include "../../../Buffers/VBO.h"
#include "../../../Buffers/EBO.h"
#include "../../Camera/Camera.h"

#include "../../Shader/Shader.h"
#include "../../../Data/Types.h"

struct CubeAttribs
{
    math::vec3f32 position;
};

class DrawCubesRenderPass
{
public:

    DrawCubesRenderPass() = default;

    void Initialize();

    void Draw(std::vector<CubeAttribs>& t_cubes_draw_commands, Camera& t_camera);

private:

    Shader m_shader_program;
    TextureArray m_texture_array;

    VAO m_vertex_attribute_object;
    VBO m_vertex_buffer;
    EBO m_element_buffer;
    
};

#endif