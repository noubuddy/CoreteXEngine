#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
// #include <cstdlib>

class Window
{
public:
    Window(unsigned short int width, unsigned short int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
    ~Window();

    GLFWwindow* CreateWindow();
    void DestroyWindow();
    
    void SetAsCurrentWindow();
    int WindowShouldClose();
    void SwapBuffers();
    void PollEvents();

    GLFWwindow* GetCurrentWindow();
    
private:
    GLFWwindow* m_window;
    GLFWmonitor* m_monitor;
    
    unsigned short int m_width;
    unsigned short int m_height;
    const char* m_title;
};

#endif