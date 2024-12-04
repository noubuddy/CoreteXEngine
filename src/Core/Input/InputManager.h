#ifndef INPUT_MANAGER_CLASS_H
#define INPUT_MANAGER_CLASS_H
#include <GLFW/glfw3.h>

class InputManager
{
public:
    InputManager(GLFWwindow* t_window);

protected:
    void BindKeyboardEvent(int t_key, int t_state, void (*t_event)());

private:
    virtual void EventBindings();

    GLFWwindow* m_window;
    
};

#endif