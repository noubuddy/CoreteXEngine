#ifndef TRANSFORM_STRUCT_H
#define TRANSFORM_STRUCT_H
#include <glm/vec3.hpp>

struct Transform
{
    
public:
    Transform() : m_location(0.f, 0.f, 0.f), m_rotation(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f)
    {
    }

    Transform(glm::vec3 location, glm::vec3 rotation, glm::vec3 scale) : m_location(location), m_rotation(rotation), m_scale(scale)
    {
    }
    
    glm::vec3 GetLocation() {return m_location;}
    glm::vec3 GetRotation() {return m_rotation;}
    glm::vec3 GetScale() {return m_scale;}

    void SetTransform(glm::vec3 location, glm::vec3 rotation, glm::vec3 scale) {m_location = location; m_rotation = rotation; m_scale = scale;}
    void SetLocation(glm::vec3 new_location) {m_location = new_location;}
    void SetRotation(glm::vec3 new_rotation) {m_rotation = new_rotation;}
    void SetScale(glm::vec3 new_scale) {m_scale = new_scale;}
    
private:
    glm::vec3 m_location;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
};

#endif
