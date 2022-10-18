#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"

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
		-0.5f, -0.5f,	0.0f,	1.0f,  0.0f,  0.0f,  0.0f,  0.0f,	// Lower left corner
		-0.5f,	0.5f,	0.0f,	0.0f,  1.0f,  0.0f,  0.0f,  1.0f,	// Upper left corner
		 0.5f,	0.5f,	0.0f,	0.0f,  0.0f,  1.0f,  1.0f,  1.0f,	// Upper right corner
		 0.5f, -0.5f,	0.0f,	1.0f,  1.0f,  1.0f,  1.0f,  0.0f	// Lower right corner
	};

	GLuint indices[] =
	{
		0, 2, 1, // Upper triangle
		0, 3, 2 // Lower triangle
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
	const GLint uni_id = glGetUniformLocation(shader_program.id, "scale");

	// texture
	Texture texture("block.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	texture.TexUnit(shader_program, "tex0", 0);
	
	// keep the window opened / main loop
	while(!glfwWindowShouldClose(window))
	{
		// specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// tell OpenGL which Shader Program we want to use
		shader_program.Activate();
		// assigns a value to the uniform (Must be done after activating Shader Program)
		glUniform1f(uni_id, 0.5f);
		// binds texture so that is appears in rendering
		texture.Bind();
		// bind the vao so OpenGL knows to use it
		vao1.Bind();
		// draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		/* glDrawArrays(GL_TRIANGLES, 0, 3); */
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
