#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
    m_transform.SetTransform(
        glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 1.f));
    
    SetIsRenderable(true);
}

ObjectBase::ObjectBase(glm::vec3 t_location, glm::vec3 t_rotation, glm::vec3 t_scale)
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
