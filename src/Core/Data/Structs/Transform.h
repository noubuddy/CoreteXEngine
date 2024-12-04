#ifndef TRANSFORM_STRUCT_H
#define TRANSFORM_STRUCT_H
#include <glm/vec3.hpp>

struct Transform
{
    
public:
    Transform() : m_location(0.f, 0.f, 0.f), m_rotation(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f)
    {
    }

    Transform(glm::vec3 t_location, glm::vec3 t_rotation, glm::vec3 t_scale) : m_location(t_location), m_rotation(t_rotation), m_scale(t_scale)
    {
    }
    
    glm::vec3 GetLocation() {return m_location;}
    glm::vec3 GetRotation() {return m_rotation;}
    glm::vec3 GetScale() {return m_scale;}

    void SetTransform(glm::vec3 t_location, glm::vec3 t_rotation, glm::vec3 t_scale) {m_location = t_location; m_rotation = t_rotation; m_scale = t_scale;}
    void SetLocation(glm::vec3 t_new_location) {m_location = t_new_location;}
    void SetRotation(glm::vec3 t_new_rotation) {m_rotation = t_new_rotation;}
    void SetScale(glm::vec3 t_new_scale) {m_scale = t_new_scale;}
    
private:
    glm::vec3 m_location;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
};

#endif
