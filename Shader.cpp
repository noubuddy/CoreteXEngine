#include "Shader.h"

std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    throw errno;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    // Read vertex and fragment source code
    std::string vertex_code = get_file_contents(vertexFile);
    std::string fragment_code = get_file_contents(fragmentFile);

    // Convert vertex and fragment source code to char array
    const char *vertex_shader_source = vertex_code.c_str();
    const char *fragment_shader_source = fragment_code.c_str();

    // create vertex shader obj and get its reference (specify, what kind of shader i gonna use)
    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    // attach vertex shader src to the vertex shader obj
    glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
    // compile the vertex shader into machine code / compile vertex shader
    glCompileShader(vertex_shader);

    // create fragment shader obj and get its reference
    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    // attach fragment shader src to the fragment shader obj
    glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
    // compile the fragment shader into machine code
    glCompileShader(fragment_shader);

    // create shader program obj and get its reference
    id = glCreateProgram();
    //attach the vertex and fragment shaders to the shader program
    glAttachShader(id, vertex_shader);
    glAttachShader(id, fragment_shader);
    // wrap-up / link all the shaders together into the shader program
    glLinkProgram(id);
	
    // delete the now useless vertex and fragment shader objects
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void Shader::Activate()
{
    // tell OpenGL which shader program we want to use
    glUseProgram(id);
}


void Shader::Delete()
{
    glDeleteProgram(id);
}


