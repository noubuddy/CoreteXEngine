#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Data/String.h"

class Window
{
public:
    Window(unsigned short int t_width, unsigned short int t_height, core::String t_title, GLFWmonitor* t_monitor, GLFWwindow* t_share);
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
    core::String m_title;
};

#endif