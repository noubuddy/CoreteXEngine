#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Graphics/Shader/Shader.h"
#include "Core/Graphics/Texture/Texture.h"
#include "Core/Graphics/Camera/Camera.h"
#include "Core/Graphics/Render/Helpers/Indices.h"
#include "Core/Graphics/Render/Renderer.h"
#include "Core/Graphics/Texture/TextureArray.h"
#include "Core/Graphics/Render/Helpers/Vertices.h"
#include "Game/World/WorldManager.h"

int main()
{
    const int width = 1920;
    const int height = 1080;

    WorldManager world_manager;
    world_manager.GenerateWorldData();
    std::vector<BlockData>* world_data = world_manager.GetWorldData();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Window", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Failed to create window \n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0, 0, width, height);

    Shader shader_program("src/Core/Graphics/Shader/Shaders/default.vert", "src/Core/Graphics/Shader/Shaders/default.frag");

    std::vector<std::string> image_paths =
    {
        "resources/block.jpg", "resources/block.jpg", "resources/block.jpg",
        "resources/block.jpg", "resources/block-top.jpg", "resources/block.jpg"
    };
    TextureArray texture_array(image_paths);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture_array.id);

    glUseProgram(shader_program.id);
    glUniform1i(glGetUniformLocation(shader_program.id, "texArray"), 0);

    Renderer renderer;

    Texture grass_top_texture("block-top.jpg", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGB, GL_UNSIGNED_BYTE);

    std::vector<GLfloat> v = Vertices::GetVertices();
    std::vector<GLuint> i = Indices::GetIndices();

    renderer.PushRenderData(v, i, grass_top_texture);

    Camera camera(width, height, glm::vec3(10.0f, 100.0f, 10.0f));

    shader_program.Activate();

    glEnable(GL_DEPTH_TEST);

    double lastTime = glfwGetTime();
    int nbFrames = 0;

    while (!glfwWindowShouldClose(window))
    {
        // Measure speed
        double currentTime = glfwGetTime();
        nbFrames++;
        if (currentTime - lastTime >= 1.0)
        {
            // If last prinf() was more than 1 sec ago
            // printf and reset timer
            // printf("%f ms/frame, %i FPS\n", 1000.0 / double(nbFrames), nbFrames);
            std::cout << 1000.0 / double(nbFrames) << " ms/frame, " << nbFrames << " FPS\n";
            nbFrames = 0;
            lastTime += 1.0;
        }

        glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.speed = 0.6f;
        camera.Inputs(window);

        for (BlockData block : *world_data)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(glm::mat4(1.0f), block.Position);

            camera.Matrix(80.0f, 0.1f, 300.0f, shader_program, "camMatrix", model);

            renderer.Render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    shader_program.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
