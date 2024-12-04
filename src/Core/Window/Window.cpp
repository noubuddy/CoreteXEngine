#include "Window.h"

Window::Window(unsigned short t_width, unsigned short t_height, const char* t_title, GLFWmonitor* t_monitor, GLFWwindow* t_share)
{
    m_width = t_width;
    m_height = t_height;
    m_title = t_title;
    m_monitor = t_monitor;
}

Window::~Window()
{
    // free(m_window);
    // free(m_monitor);
}

GLFWwindow* Window::CreateWindow()
{
    m_window = glfwCreateWindow(m_width, m_height, m_title, m_monitor, nullptr);
    return m_window;
}

void Window::DestroyWindow()
{
    glfwDestroyWindow(m_window);
}

void Window::SetAsCurrentWindow()
{
    if (!m_window)
    {
        // TODO: add check
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);
    gladLoadGL();
    glViewport(0, 0, m_width, m_height);
}

GLFWwindow* Window::GetCurrentWindow()
{
    return m_window;
}

int Window::WindowShouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(m_window);
}

void Window::PollEvents()
{
    glfwPollEvents();
}
