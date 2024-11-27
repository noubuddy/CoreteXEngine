#ifndef OBJECT_BASE_CLASS_H
#define OBJECT_BASE_CLASS_H
#include <glm/vec3.hpp>
#include "../Data/Structs/Transform.h"

class ObjectBase
{

public:
    ObjectBase();
    ObjectBase(glm::vec3 location, glm::vec3 rotation, glm::vec3 scale);
    ObjectBase(Transform transform);
    virtual ~ObjectBase() = default;

    Transform GetTransform() {return m_transform;}
    glm::vec3 GetLocation() {return m_transform.GetLocation();}
    glm::vec3 GetRotation() {return m_transform.GetRotation();}
    glm::vec3 GetScale() {return m_transform.GetScale();}
    bool IsRenderable() {return m_is_renderable;}

    void SetTransform(Transform new_transform) {m_transform = new_transform;}
    void SetLocation(glm::vec3 new_location) {m_transform.SetLocation(new_location);}
    void SetRotation(glm::vec3 new_rotation) {m_transform.SetRotation(new_rotation);}
    void SetScale(glm::vec3 new_scale) {m_transform.SetScale(new_scale);}
    void SetIsRenderable(bool is_renderable) {m_is_renderable = is_renderable;}
    
    void Spawn();
    
    void Update();

private:
    Transform m_transform;
    
    bool m_is_renderable;
};

#endif