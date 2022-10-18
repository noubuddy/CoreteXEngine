#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

int main()
{
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
		-0.5f,     -0.5f * float(sqrt(3)) / 3,    0.0f, 0.8f, 0.3f,  0.02f, // Lower left corner
		0.5f,      -0.5f * float(sqrt(3)) / 3,    0.0f,	0.8f, 0.3f,  0.02f, // Lower right corner
		0.0f,	   0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	1.0f, 0.6f,  0.32f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6,     0.0f,	0.9f, 0.45f, 0.17f, // Inner left
		0.5f / 2,  0.5f * float(sqrt(3)) / 6,     0.0f,	0.9f, 0.45f, 0.17f, // Inner right
		0.0f,      -0.5f * float(sqrt(3)) / 3,    0.0f, 0.8f, 0.3f,  0.02f, // Inner down
	};

	GLuint indices[] =
	{
		0, 3, 5,	// Lower left triangle
		3, 2, 4,	// Lower right triangle
		5, 4, 1		// Upper triangle
	};
	/*--------------------------------------------------------------------------------------------------------------*/

	/*---------------------------------------------CREATE WINDOW----------------------------------------------------*/
	
	// create window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Window", nullptr, nullptr);
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
	glViewport(0, 0, 800, 800);

	/*--------------------------------------------------------------------------------------------------------------*/

	/*------------------------------------------------MAIN FUNCTIONALITY--------------------------------------------*/
	// create shader program
	Shader shader_program("default.vert", "default.frag");

	// create reference container for the vertex array object and bind it
	VAO vao1;
	vao1.Bind();

	// introduce the vertices into the vbo
	VBO vbo1(vertices, sizeof(vertices));

	// introduce the indices into the ebo
	EBO ebo1(indices, sizeof(indices));

	// wrap-up / link all the shaders together into the shader program
	vao1.LinkAttrib(vbo1, 0, 3, GL_FLOAT, 6 * sizeof(float), nullptr);
	vao1.LinkAttrib(vbo1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	
	// unbinds
	vao1.Unbind();
	vbo1.Unbind();
	ebo1.Unbind();

	const GLint uni_id = glGetUniformLocation(shader_program.id, "scale");
	
	// keep the window opened / main loop
	while(!glfwWindowShouldClose(window))
	{
		// specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// activate shader program
		shader_program.Activate();
		glUniform1f(uni_id, 0.5f);
		// bind the vao so OpenGL knows to use it
		vao1.Bind();
		// draw triangle using the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);
		/* glDrawArrays(GL_TRIANGLES, 0, 3); */
		glfwSwapBuffers(window);
		// process all the pooled events / make the window responding / take care of all GLFW event
		glfwPollEvents();
	}

	// delete all the objects we've created
	vao1.Delete();
	vbo1.Delete();
	ebo1.Delete();
	shader_program.Delete();

	// destroy window before ending the program
	glfwDestroyWindow(window);

	// terminate glfw before ending the program
	glfwTerminate();
	/*--------------------------------------------------------------------------------------------------------------*/
	
	return 0;
}