#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

class Shader
{
public:
    GLuint id;
    Shader(const char* vertexFile, const char* fragmentFile);
    void Activate();
    void Delete();

private:
    std::string ReadFile(const char* filename);
    void CompileShader(unsigned int shader);
};
#endif