#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "../../Utils/Imgui.h"
#include "../Shader/Shader.h"
#include "../../Data/String.h"

class Camera
{
public:
    glm::vec3 position;
    glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    bool first_click = true;
    
    int width;
    int height;

    float speed = 50.0f;
    float sensitivity = 100.0f;

    Camera() = default;
    Camera(int t_width, int t_height, glm::vec3 t_position);

    void Tick(float& t_delta_time, GLFWwindow* t_window);

    glm::mat4 GetViexMatrix();
    void Matrix(float t_fov_deg, float t_near_plane, float t_far_plane, Shader& t_shader, core::String t_uniform, glm::mat4 t_model);
    void Inputs(GLFWwindow *t_window, float& t_delta_time);

    // getters
    float GetPosX();
    float GetPosY();
    float GetPosZ();

    // setters
    void SetPosX(float t_new_pos_x);
    void SetPosY(float t_new_pos_y);
    void SetPosZ(float t_new_pos_z);
};


#endif