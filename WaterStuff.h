#ifndef WATER_STUFF_CLASS
#define WATER_STUFF_CLASS
#include <glad/glad.h>

class WaterStuff
{
public:

    inline static void water_stuff()
    {
        // Define the water mesh
        GLfloat water_vertices[] = {
            // front face
            -1.0f, -1.0f,  0.0f,
             1.0f, -1.0f,  0.0f,
             1.0f,  1.0f,  0.0f,
            -1.0f,  1.0f,  0.0f,
            // back face
            -1.0f, -1.0f, -0.1f,
             1.0f, -1.0f, -0.1f,
             1.0f,  1.0f, -0.1f,
            -1.0f,  1.0f, -0.1f
        };

        GLuint water_indices[] = {
            0, 1, 2, 3, // front face
            1, 5, 6, 2, // right face
            5, 4, 7, 6, // back face
            4, 0, 3, 7, // left face
            3, 2, 6, 7, // top face
            0, 4, 5, 1  // bottom face
        };

        // Create the water shader program
        GLuint water_program = 0;
        GLuint water_vao = 0;
        GLuint water_vbo = 0;
        GLuint water_ebo = 0;

        
    }
    
};

#endif