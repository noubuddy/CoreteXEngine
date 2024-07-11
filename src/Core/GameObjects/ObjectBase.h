#ifndef OBJECT_BASE_CLASS_H
#define OBJECT_BASE_CLASS_H
#include <glm/vec3.hpp>

class ObjectBase
{
    
private:
    glm::vec3 m_location;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;

public:
    ObjectBase();
    ObjectBase(glm::vec3 Location, glm::vec3 Rotation, glm::vec3 Scale);

    glm::vec3 GetLocation() {return m_location;}
    glm::vec3 GetRotation() {return m_rotation;}
    glm::vec3 GetScale() {return m_scale;}

    void SetLocation(glm::vec3 NewLocation) {m_location = NewLocation;}
    void SetRotation(glm::vec3 NewRotation) {m_rotation = NewRotation;}
    void SetScale(glm::vec3 NewScale) {m_scale = NewScale;}
};

#endif