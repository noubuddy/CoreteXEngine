#include "Window.h"

Window::Window(unsigned short width, unsigned short height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
    m_width = width;
    m_height = height;
    m_title = title;
    m_monitor = monitor;
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
