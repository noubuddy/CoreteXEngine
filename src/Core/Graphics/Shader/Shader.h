#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include "../../Data/String.h"

class Shader
{
public:
    Shader() = default;
    
    GLuint id;
    Shader(core::String t_vertex_file, core::String t_fragment_file);
    void Activate();
    void Delete();

private:
    core::String ReadFile(core::String& t_filename);
    void CompileShader(unsigned int t_shader);
};
#endif