#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"

int main()
{
    int width = 1000;
    int height = 1000;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] =
    {
        -0.5f,  0.0f,   0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 0.0f, // A1
        -0.5f,  0.0f,  -0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 0.0f, // B1
         0.5f,  0.0f,  -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 0.0f, // C1
         0.5f,  0.0f,   0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 0.0f, // D1
        
        -0.5f,  1.0f,   0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 1.0f, // A2
        -0.5f,  1.0f,  -0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 1.0f, // B2
         0.5f,  1.0f,  -0.5f,   1.0f, 0.0f, 0.0f,    0.0f, 1.0f, // C2
         0.5f,  1.0f,   0.5f,   1.0f, 0.0f, 0.0f,    1.0f, 1.0f  // D2
    };

    GLuint indices[] =
    {
        0, 1, 2, 
        0, 3, 2,
        6, 5, 2, 
        5, 1, 2, 
        3, 7, 2, 
        6, 7, 2, 
        3, 0, 4, 
        3, 7, 4,
        0, 1, 5,
        0, 4, 5,
        4, 5, 6,
        4, 7, 6
    };

    glm::vec3 cubePositions[] = {
        glm::vec3( 1.0f,  1.0f,  0.0f),
        glm::vec3( 2.0f,  1.0f,  0.0f),
        glm::vec3( 3.0f,  1.0f,  0.0f),
        glm::vec3( 4.0f,  1.0f,  0.0f),
        glm::vec3( 5.0f,  1.0f,  0.0f),
        glm::vec3( 1.0f,  1.0f,  1.0f),
        glm::vec3( 2.0f,  1.0f,  1.0f),
        glm::vec3( 3.0f,  1.0f,  1.0f),
        glm::vec3( 4.0f,  1.0f,  1.0f),
        glm::vec3( 5.0f,  1.0f,  1.0f)
    };

    GLFWwindow* window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create window \n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, width, height);

    Shader shader_program("default.vert", "default.frag");

    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices, sizeof(vertices));
    EBO ebo1(indices, sizeof(indices));

    vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), nullptr);
    vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    
    vao1.Unbind();
    vbo1.Unbind();
    ebo1.Unbind();

    Texture texture("block.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    texture.TexUnit(shader_program, "tex0", 0);

    glEnable(GL_DEPTH_TEST);

    Camera camera(width, height, glm::vec3(0.0f, 0.5f, 5.0f));

    shader_program.Activate();

    double lastTime = glfwGetTime();
    int nbFrames = 0;

    while (!glfwWindowShouldClose(window))
    {
        // FPS couonter
        double currentTime = glfwGetTime();
        nbFrames++;
        if ( currentTime - lastTime >= 1.0 ){
            std::cout << 1000.0/double(nbFrames) << std::endl;
            nbFrames = 0;
            lastTime += 1.0;
        }
        
        glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        camera.speed = 0.001f;
        camera.Inputs(window);

        texture.Bind();
        vao1.Bind();

        for (int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            float angle = 20.0f * i;
            
            model = glm::translate(model, cubePositions[i]);
            // model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            
            camera.Matrix(80.0f, 0.1f, 100.0f, shader_program, "camMatrix", model);
            
            glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, nullptr);
        }
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    vao1.Delete();
    vbo1.Delete();
    ebo1.Delete();
    texture.Delete();
    shader_program.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
