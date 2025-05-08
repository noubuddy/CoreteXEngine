#ifndef OBJECT_BASE_CLASS_H
#define OBJECT_BASE_CLASS_H
#include <glm/vec3.hpp>
#include "../Data/Structs/Transform.h"

class ObjectBase
{

public:
    ObjectBase();
    ObjectBase(math::vec3f32 t_location, math::vec3f32 t_rotation, math::vec3f32 t_scale);
    ObjectBase(Transform t_transform);
    virtual ~ObjectBase() = default;

    Transform GetTransform() {return m_transform;}
    math::vec3f32 GetLocation() {return m_transform.GetLocation();}
    math::vec3f32 GetRotation() {return m_transform.GetRotation();}
    math::vec3f32 GetScale() {return m_transform.GetScale();}
    bool IsRenderable() {return m_is_renderable;}

    void SetTransform(Transform t_new_transform) {m_transform = t_new_transform;}
    void SetLocation(math::vec3f32 t_new_location) {m_transform.SetLocation(t_new_location);}
    void SetRotation(math::vec3f32 t_new_rotation) {m_transform.SetRotation(t_new_rotation);}
    void SetScale(math::vec3f32 t_new_scale) {m_transform.SetScale(t_new_scale);}
    void SetIsRenderable(bool t_is_renderable) {m_is_renderable = t_is_renderable;}
    
    void Spawn();
    
    void Update();

private:
    Transform m_transform;
    
    bool m_is_renderable;
};

#endif