#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
    m_location = glm::vec3(0.f, 0.f, 0.f);
    m_rotation = glm::vec3(0.f, 0.f, 0.f);
    m_scale = glm::vec3(0.f, 0.f, 0.f);
}

ObjectBase::ObjectBase(glm::vec3 Location, glm::vec3 Rotation, glm::vec3 Scale)
{
    m_location = Location;
    m_rotation = Rotation;
    m_scale = Scale;
}
