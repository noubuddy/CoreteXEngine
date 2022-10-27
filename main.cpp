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
    /*--------------------------------------------INITIALIZATION----------------------------------------------------*/
    // init glfw
    glfwInit();
    // tell glfw what version of OpenGL we are using (3.3)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // tell glfw we are using the CORE profile so we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /*--------------------------------------------------------------------------------------------------------------*/

    /*------------------------------------------VERTICES AND INDICES------------------------------------------------*/
    // vertices coordinates
    GLfloat vertices[] =
    {
        //x    //y    //z
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
        0, 4, 5
    };
    /*--------------------------------------------------------------------------------------------------------------*/

    /*---------------------------------------------CREATE WINDOW----------------------------------------------------*/

    // create window
    GLFWwindow* window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
    // check an issues while creating the window
    if (window == nullptr)
    {
        std::cout << "Failed to create window \n";
        glfwTerminate();
        return -1;
    }
    // introduce the window into the current context
    glfwMakeContextCurrent(window);
    // load GLAD so it configures OpenGL
    gladLoadGL();
    // specify the viewport of OpenGl in the window
    glViewport(0, 0, width, height);

    /*--------------------------------------------------------------------------------------------------------------*/

    /*------------------------------------------------MAIN FUNCTIONALITY--------------------------------------------*/
    // create shader program
    Shader shader_program("default.vert", "default.frag");

    // generates Vertex Array Object and binds it
    VAO vao1;
    vao1.Bind();

    // generates Vertex Buffer Object and links it to vertices
    VBO vbo1(vertices, sizeof(vertices));
    // generates Element Buffer Object and links it to indices
    EBO ebo1(indices, sizeof(indices));

    // links VBO attributes such as coordinates and colors to VAO
    vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), nullptr);
    vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    
    // unbind all to prevent accidentally modifying them
    vao1.Unbind();
    vbo1.Unbind();
    ebo1.Unbind();

    // gets ID of uniform called "scale"
    // const GLint uni_id = glGetUniformLocation(shader_program.id, "scale");

    // texture
    Texture texture("block.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    texture.TexUnit(shader_program, "tex0", 0);

    // variables that help the rotation of the block
    // float rotation = 0.0f;
    // double prev_time = glfwGetTime();

    // enables the Depth Buffer
    glEnable(GL_DEPTH_TEST);

    Camera camera(width, height, glm::vec3(0.0f, 0.5f, 5.0f));

    // keep the window opened / main loop
    while (!glfwWindowShouldClose(window))
    {
        // specify the color of the background
        glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
        // clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // tell OpenGL which Shader Program we want to use
        shader_program.Activate();

        
        camera.Inputs(window);
        camera.Matrix(80.0f, 0.1f, 100.0f, shader_program, "camMatrix");

        // timer
        // double current_time = glfwGetTime();
        // if (current_time - prev_time >= 1 / 60)
        // {
        //     rotation += 1.0f;
        //     prev_time = current_time;
        // }

        // glm::mat4 model = glm::mat4(1.0f);
        // glm::mat4 view = glm::mat4(1.0f);
        // glm::mat4 proj = glm::mat4(1.0f);
        //
        // model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, -1.0f, 0.0f));
        // view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
        // proj = glm::perspective(glm::radians(45.0f), (float)(width / height), 0.1f, 100.0f);
        //
        // int model_location = glGetUniformLocation(shader_program.id, "model");
        // glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
        // int view_location = glGetUniformLocation(shader_program.id, "view");
        // glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
        // int proj_location = glGetUniformLocation(shader_program.id, "proj");
        // glUniformMatrix4fv(proj_location, 1, GL_FALSE, glm::value_ptr(proj));

        // assigns a value to the uniform (Must be done after activating Shader Program)
        // glUniform1f(uni_id, 0.5f);
        // binds texture so that is appears in rendering
        texture.Bind();
        // bind the vao so OpenGL knows to use it
        vao1.Bind();
        // draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, nullptr);
        // glDrawArrays(GL_TRIANGLES, 0, 8);
        // swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // process all the pooled events / make the window responding / take care of all GLFW event
        glfwPollEvents();
    }

    // delete all the objects we've created
    vao1.Delete();
    vbo1.Delete();
    ebo1.Delete();
    texture.Delete();
    shader_program.Delete();

    // destroy window before ending the program
    glfwDestroyWindow(window);

    // terminate glfw before ending the program
    glfwTerminate();
    /*--------------------------------------------------------------------------------------------------------------*/

    return 0;
}
