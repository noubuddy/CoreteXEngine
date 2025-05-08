#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
    m_transform.SetTransform(
        math::vec3f32(0.f, 0.f, 0.f),
        math::vec3f32(0.f, 0.f, 0.f),
        math::vec3f32(1.f, 1.f, 1.f));
    
    SetIsRenderable(true);
}

ObjectBase::ObjectBase(math::vec3f32 t_location, math::vec3f32 t_rotation, math::vec3f32 t_scale)
{
    m_transform.SetTransform(
        t_location,
        t_rotation,
        t_scale);

    SetIsRenderable(true);
}

ObjectBase::ObjectBase(Transform t_transform)
{
    m_transform = t_transform;

    SetIsRenderable(true);
}

void ObjectBase::Spawn()
{
}

void ObjectBase::Update()
{
}
