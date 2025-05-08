#include "Shader.h"

Shader::Shader(core::String t_vertex_file, core::String t_fragment_file)
{
    core::String vertexCode = ReadFile(t_vertex_file);
    core::String fragmentCode = ReadFile(t_fragment_file);

    const char* vertexShaderSource = vertexCode.GetData();
    const char* fragmentShaderSource = fragmentCode.GetData();

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

core::String Shader::ReadFile(core::String& t_filename)
{
    std::ifstream in(t_filename.GetData(), std::ios::binary);

    if (!in)
        throw errno;

    core::String content;
    in.seekg(0, std::ios::end);
    content.Resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&content[0], content.Size());
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


