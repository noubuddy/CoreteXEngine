#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Core/Engine.h"
#include "Core/Graphics/Shader/Shader.h"
#include "Core/Graphics/Texture/TextureSingle.h"
#include "Core/Graphics/Camera/Camera.h"
#include "Core/Graphics/Render/Helpers/Indices.h"
#include "Core/Graphics/Render/Renderer.h"
#include "Core/Graphics/Texture/TextureArray.h"
#include "Core/Graphics/Render/Helpers/Vertices.h"
#include "Core/Window/Window.h"

#include "Game/World/WorldManager.h"

int main()
{
    // const int width = 1920;
    // const int height = 1080;
    //
    // WorldManager world_manager;
    // world_manager.GenerateWorldData();
    // std::vector<Block*>* world_data = world_manager.GetWorldData();

    // glfwInit();
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window* window = new Window(1920, 1080, "CoreteXngin", nullptr, nullptr);
    // if (!window->CreateWindow())
    // {
    //     return -1;
    // }
    //
    // window->SetAsCurrentWindow();
    //
    // Shader shader_program("src/Core/Graphics/Shader/Shaders/default.vert", "src/Core/Graphics/Shader/Shaders/default.frag");
    //
    // std::vector<std::string> image_paths =
    // {
    //     "resources/block.jpg", "resources/block.jpg", "resources/block.jpg",
    //     "resources/block.jpg", "resources/block-top.jpg", "resources/block.jpg"
    // };
    //
    // TextureArray texture_array(image_paths, GL_TEXTURE_2D_ARRAY, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    // texture_array.TexUnit(shader_program, "texArray", 0);
    // texture_array.Bind();
    //
    // Renderer renderer;
    //
    // std::vector<GLfloat> v = Vertices::GetVertices();
    // std::vector<GLuint> i = Indices::GetIndices();
    //
    // renderer.PushRenderData(v, i, texture_array);
    //
    // Camera camera(width, height, glm::vec3(10.0f, 100.0f, 10.0f));
    //
    // shader_program.Activate();
    //
    // renderer.EnableDepthTest(true);
    // renderer.SetVSyncFreq(0);
    //
    // double lastTime = glfwGetTime();
    // int nbFrames = 0;
    //
    // while (!window->WindowShouldClose())
    // {
    //     // Measure speed
    //     double currentTime = glfwGetTime();
    //     nbFrames++;
    //     if (currentTime - lastTime >= 1.0)
    //     {
    //         // If last prinf() was more than 1 sec ago
    //         // printf and reset timer
    //         // printf("%f ms/frame, %i FPS\n", 1000.0 / double(nbFrames), nbFrames);
    //         std::cout << 1000.0 / double(nbFrames) << " ms/frame, " << nbFrames << " FPS\n";
    //         nbFrames = 0;
    //         lastTime += 1.0;
    //     }
    //
    //     glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
    //     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //
    //     camera.Inputs(window->GetCurrentWindow());
    //
    //     for (Block* block : *world_data)
    //     {
    //         glm::mat4 model = glm::mat4(1.0f);
    //         model = glm::translate(glm::mat4(1.0f), block->GetLocation());
    //
    //         camera.Matrix(80.0f, 0.1f, 300.0f, shader_program, "camMatrix", model);
    //
    //         renderer.Render();
    //     }
    //
    //     window->SwapBuffers();
    //     glfwPollEvents();
    // }
    //
    // shader_program.Delete();
    // window->DestroyWindow();
    // glfwTerminate();

    Engine* engine = new Engine();
    if (!engine)
    {
        return -1;
    }

    engine->CreateDefaultGameWorld();

    engine->StartUp();

    return 0;
}
