#include "Camera.h"

Camera::Camera(int t_width, int t_height, glm::vec3 t_position)
{
    width = t_width;
    height = t_height;
    position = t_position;
}

void Camera::Tick(float& t_delta_time, GLFWwindow* t_window)
{
    Inputs(t_window, t_delta_time);
}

glm::mat4 Camera::GetViexMatrix()
{
    return glm::lookAt(position, position + orientation, up);
}

void Camera::Matrix(float t_fov_deg, float t_near_plane, float t_far_plane, Shader& t_shader, const char* t_uniform, glm::mat4 t_model)
{
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(position, position + orientation, up);

    float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
    projection = glm::perspective(glm::radians(t_fov_deg), aspectRatio, t_near_plane, t_far_plane);

    glUniformMatrix4fv(glGetUniformLocation(t_shader.id, t_uniform), 1, GL_FALSE, glm::value_ptr(projection * view * t_model));
}

void Camera::Inputs(GLFWwindow* t_window, float& t_delta_time)
{
    float adjustedSpeed = speed * t_delta_time;
    
    if (glfwGetKey(t_window, GLFW_KEY_W) == GLFW_PRESS)
    {
        position += adjustedSpeed * orientation;
    }
    
    if (glfwGetKey(t_window, GLFW_KEY_A) == GLFW_PRESS)
    {
        position += adjustedSpeed * -glm::normalize(glm::cross(orientation, up));
    }
    
    if (glfwGetKey(t_window, GLFW_KEY_S) == GLFW_PRESS)
    {
        position += adjustedSpeed * -orientation;
    }
    
    if (glfwGetKey(t_window, GLFW_KEY_D) == GLFW_PRESS)
    {
        position += adjustedSpeed * glm::normalize(glm::cross(orientation, up));
    }

    if (glfwGetKey(t_window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        position += adjustedSpeed * up;
    }

    if (glfwGetKey(t_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        position += adjustedSpeed * -up;
    }

    if (glfwGetKey(t_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        speed = 100.0f;
    }

    else if (glfwGetKey(t_window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
    {
        speed = 50.0f;
    }

    if (glfwGetMouseButton(t_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !Imgui::WantCaptureMouse())
    {
        glfwSetInputMode(t_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        if (first_click)
        {
            glfwSetCursorPos(t_window, (width / 2), (height / 2));
            first_click = false;
        }

        double mouseX;
        double mouseY;
        glfwGetCursorPos(t_window, &mouseX, &mouseY);

        float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
        float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

        glm::vec3 newOrientation = glm::rotate(orientation, glm::radians(-rotX), glm::normalize(glm::cross(orientation, up)));

        if (abs(glm::angle(newOrientation, up) - glm::radians(90.0f)) <= glm::radians(85.0f))
        {
            orientation = newOrientation;
        }

        orientation = glm::rotate(orientation, glm::radians(-rotY), up);

        glfwSetCursorPos(t_window, (width / 2), (height / 2));
    }
    else if (glfwGetMouseButton(t_window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        glfwSetInputMode(t_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        first_click = true;
    }
}

float Camera::GetPosX()
{
    return position.x;
}

float Camera::GetPosY()
{
    return position.y;
}

float Camera::GetPosZ()
{
    return position.z;
}

void Camera::SetPosX(float t_new_pos_x)
{
    position.x = t_new_pos_x;
}

void Camera::SetPosY(float t_new_pos_y)
{
    position.y = t_new_pos_y;
}

void Camera::SetPosZ(float t_new_pos_z)
{
    position.z = t_new_pos_z;
}
