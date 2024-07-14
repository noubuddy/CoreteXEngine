#ifndef INPUT_MANAGER_CLASS_H
#define INPUT_MANAGER_CLASS_H
#include <GLFW/glfw3.h>

class InputManager
{
public:
    InputManager(GLFWwindow* window);

protected:
    void BindKeyboardEvent(int key, int state, void (*event)());

private:
    virtual void EventBindings();

    GLFWwindow* window;
    
};

#endif