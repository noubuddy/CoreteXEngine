﻿#include "Shader.h"

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    std::string vertex_code = ReadFile(vertexFile);
    std::string fragment_code = ReadFile(fragmentFile);

    const char *vertex_shader_source = vertex_code.c_str();
    const char *fragment_shader_source = fragment_code.c_str();

    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
    CompileShader(vertex_shader);

    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
    CompileShader(fragment_shader);

    id = glCreateProgram();
    glAttachShader(id, vertex_shader);
    glAttachShader(id, fragment_shader);
    glLinkProgram(id);
	
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void Shader::Activate()
{
    glUseProgram(id);
}


void Shader::Delete()
{
    glDeleteProgram(id);
}

std::string Shader::ReadFile(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);

    if (!in)
        throw errno;

    std::string content;
    in.seekg(0, std::ios::end);
    content.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&content[0], content.size());
    in.close();
    return content;
}

void Shader::CompileShader(unsigned shader)
{
    glCompileShader(shader);

    int result;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    
    if (result == false)
    {
        int lenght;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*)alloca(lenght * sizeof(char));
        glGetShaderInfoLog(shader, lenght, &lenght, message);
        glDeleteProgram(shader);
        
        std::cout << "Error occured when compiling shaders\n";
        std::cout << message << "\n";
    }
}


