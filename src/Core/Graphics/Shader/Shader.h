#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader
{
public:
    GLuint id;
    Shader(const char* t_vertex_file, const char* t_fragment_file);
    void Activate();
    void Delete();

private:
    std::string ReadFile(const char* t_filename);
    void CompileShader(unsigned int t_shader);
};
#endif