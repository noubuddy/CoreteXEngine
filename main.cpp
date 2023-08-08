#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"
#include "PerlinNoise.h"
#include "Vertices.h"

GLuint indices[] =
{
    // Front Face
    0, 1, 2,
    0, 3, 2,
    // Back Face
    4, 5, 6,
    4, 7, 6,
    // Top face
    8, 9, 10,
    8, 11, 10,
    // Bottom Face
    12, 13, 14,
    12, 15, 14,
    // Right Face
    16, 17, 18,
    16, 19, 18,
    // Left Face
    20, 21, 22,
    20, 23, 22,
};

GLfloat Vertices[192];

enum BlockType
{
    GRASS,
    WATER,
    SAND
};

struct BlockData
{
    glm::vec3 Position;
    BlockType Type;
};

int main()
{
    const int width = 2560;
    const int height = 1440;

    std::vector<BlockData> WorldData;
    
    std::vector<GLfloat> vertices = Vertices::GetVertices();

    // Constants for the grid size and cube size
    const float CUBE_SIZE = 1.f;
    const float THRESHOLD = 0.4f;

    // Constants for the noise parameters
    const float NOISE_SCALE = 0.05f;

    // Initialize the Perlin noise object
    PerlinNoise noise;
    std::vector<std::vector<float>> noiseValues(GRID_SIZE, std::vector<float>(GRID_SIZE));

    // Fill noiseValues array
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            for (int z = 0; z < GRID_SIZE; ++z)
            {
                noiseValues[y][x] = noise.noise(x * NOISE_SCALE, y * NOISE_SCALE, z * NOISE_SCALE);
            }
        }
    }

    // Generate world array
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            float noiseValue = noiseValues[y][x];
            
            // get first digit after the dot
            float afterDotValue = static_cast<int>(std::floor(std::fabs(noiseValue) * 10)) % 10;

            BlockData blockData{};
            blockData.Position = glm::vec3(x * CUBE_SIZE, afterDotValue * CUBE_SIZE, y * CUBE_SIZE);

            if (noiseValue > THRESHOLD)
            {
                blockData.Type = GRASS;
            }
            else if (noiseValue > 0.37 && noiseValue < THRESHOLD)
            {
                blockData.Type = SAND;
            }
            else
            {
                blockData.Type = WATER;
            }

            WorldData.emplace_back(blockData);
        }
    }

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

    Shader shader_program("default.vert", "default.frag");

    VAO vao1;
    vao1.Bind();

    VBO vbo1(vertices);
    EBO ebo1(indices, sizeof indices);

    vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 8 * sizeof(float), nullptr);
    vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    vao1.LinkAttrib(vbo1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    vao1.Unbind();
    vbo1.Unbind();
    ebo1.Unbind();

    Texture grass_top("block-top.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    grass_top.TexUnit(shader_program, "tex0", 0);

    Texture water("water.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    water.TexUnit(shader_program, "tex0", 0);

    Texture sand("sand2.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    sand.TexUnit(shader_program, "tex0", 0);
    
    Camera camera(width, height, glm::vec3(10.0f, 100.0f, 10.0f));

    shader_program.Activate();
    
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.speed = 0.6f;
        camera.Inputs(window);
        vao1.Bind();

        for (auto block : WorldData)
        {
            switch (block.Type)
            {
                case GRASS:
                    grass_top.Bind();
                    break;
                case SAND:
                    sand.Bind();
                    break;
                case WATER:
                    water.Bind();
                    break;
            }

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(glm::mat4(1.0f),
                                   block.Position);

            camera.Matrix(80.0f, 0.1f, 300.0f, shader_program, "camMatrix", model);
            glDrawElements(GL_TRIANGLES, sizeof indices / sizeof(int), GL_UNSIGNED_INT, nullptr);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    vao1.Delete();
    vbo1.Delete();
    ebo1.Delete();

    grass_top.Delete();
    water.Delete();

    shader_program.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
