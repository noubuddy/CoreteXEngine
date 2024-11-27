#ifndef RENDERER_CLASS_H
#define RENDERER_CLASS_H

#include "../../Data/Structs/RenderData.h"
#include "../../Buffers/EBO.h"
#include "../Texture/TextureArray.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Renderer
{
public:
    
    void Render();
    
    void PushRenderData(std::vector<GLfloat>& vertices, std::vector<GLuint>& indices, TextureBase& texture);

    void EnableDepthTest(bool enable);

    void SetVSyncFreq(unsigned short t_frequency);

    Shader* GetShaderProgram() {return m_shader_program;}

    void SetShaderProgram(Shader* t_shader_program) {m_shader_program = t_shader_program;}

private:

    std::vector<RenderData> mRenderData;

    Shader* m_shader_program;
    
};

#endif