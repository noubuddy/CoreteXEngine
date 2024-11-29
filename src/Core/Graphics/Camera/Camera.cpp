#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
    Camera::width = width;
    Camera::height = height;
    Position = position;
}

glm::mat4 Camera::GetViexMatrix()
{
    return glm::lookAt(Position, Position + Orientation, Up);
}

void Camera::Matrix(float fov_deg, float near_plane, float far_plane, Shader& shader, const char* uniform, glm::mat4 model)
{
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(Position, Position + Orientation, Up);

    float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
    projection = glm::perspective(glm::radians(fov_deg), aspectRatio, near_plane, far_plane);

    glUniformMatrix4fv(glGetUniformLocation(shader.id, uniform), 1, GL_FALSE, glm::value_ptr(projection * view * model));
}

void Camera::Inputs(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        Position += speed * Orientation;
    }
    
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        Position += speed * -glm::normalize(glm::cross(Orientation, Up));
    }
    
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        Position += speed * -Orientation;
    }
    
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        Position += speed * glm::normalize(glm::cross(Orientation, Up));
    }

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        Position += speed * Up;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        Position += speed * -Up;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        speed = 1.f;
    }

    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
    {
        speed = 0.6f;
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !Imgui::WantCaptureMouse())
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        if (firstClick)
        {
            glfwSetCursorPos(window, (width / 2), (height / 2));
            firstClick = false;
        }

        double mouseX;
        double mouseY;
        glfwGetCursorPos(window, &mouseX, &mouseY);

        float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
        float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

        glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

        if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
        {
            Orientation = newOrientation;
        }

        Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

        glfwSetCursorPos(window, (width / 2), (height / 2));
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }

    // std::cout << "Pos: " << Position.x << ", " << Position.y << ", " << Position.z << "\n";
    // std::cout << "Orientation: " << Orientation.x << ", " << Orientation.y << ", " << Orientation.z << "\n";
}

float Camera::GetPosX()
{
    return Position.x;
}

float Camera::GetPosY()
{
    return Position.y;
}

float Camera::GetPosZ()
{
    return Position.z;
}

void Camera::SetPosX(float newPosX)
{
    Position.x = newPosX;
}

void Camera::SetPosY(float newPosY)
{
    Position.y = newPosY;
}

void Camera::SetPosZ(float newPosZ)
{
    Position.z = newPosZ;
}
