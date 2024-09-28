#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
    m_transform.SetTransform(
        glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(0.f, 0.f, 0.f),
        glm::vec3(1.f, 1.f, 1.f));
    
    SetIsRenderable(true);
}

ObjectBase::ObjectBase(glm::vec3 location, glm::vec3 rotation, glm::vec3 scale)
{
    m_transform.SetTransform(
        location,
        rotation,
        scale);

    SetIsRenderable(true);
}

ObjectBase::ObjectBase(Transform transform)
{
    m_transform = transform;

    SetIsRenderable(true);
}

void ObjectBase::Spawn()
{
}
