#include "Shader.h"

Shader::Shader(const char* t_vertex_file, const char* t_fragment_file)
{
    std::string vertexCode = ReadFile(t_vertex_file);
    std::string fragmentCode = ReadFile(t_fragment_file);

    const char *vertexShaderSource = vertexCode.c_str();
    const char *fragmentShaderSource = fragmentCode.c_str();

    const GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    CompileShader(vertexShader);

    const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    CompileShader(fragmentShader);

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
	
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
    glUseProgram(id);
}


void Shader::Delete()
{
    glDeleteProgram(id);
}

std::string Shader::ReadFile(const char* t_filename)
{
    std::ifstream in(t_filename, std::ios::binary);

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

void Shader::CompileShader(unsigned t_shader)
{
    glCompileShader(t_shader);

    int result;
    glGetShaderiv(t_shader, GL_COMPILE_STATUS, &result);
    
    if (result == false)
    {
        int lenght;
        glGetShaderiv(t_shader, GL_INFO_LOG_LENGTH, &lenght);
        char* message = (char*)alloca(lenght * sizeof(char));
        glGetShaderInfoLog(t_shader, lenght, &lenght, message);
        glDeleteProgram(t_shader);
        
        std::cout << "Error occured when compiling shaders\n";
        std::cout << message << "\n";
    }
}


