#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

int main()
{
	// init glfw
	glfwInit();
	
	// tell glfw what version of OpenGL we are using (3.3)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// tell glfw we are using the CORE profile so we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// vertices coordinates
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,		// Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	// Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f		// Inner down
	};

	GLuint indices[] =
	{
		0, 3, 5,	// Lower left triangle
		3, 2, 4,	// Lower right triangle
		5, 4, 1		// Upper triangle
	};
	
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
	
	Shader shader_program("default.vert", "default.frag");

	VAO vao1;
	vao1.Bind();

	VBO vbo1(vertices, sizeof(vertices));
	EBO ebo1(indices, sizeof(indices));

	vao1.LinkVBO(vbo1, 0);
	
	vao1.Unbind();
	vbo1.Unbind();
	ebo1.Unbind();

	// keep the window opened / main loop
	while(!glfwWindowShouldClose(window))
	{
		// specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// tell OpenGL which shader program we want to use
		shader_program.Activate();
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
	return 0;
}