#include "CameraControlSystem.h"
#include "../ECS/Coordinator.h"
#include "../Data/Structs/Transform.h"

extern Coordinator g_coordinator;

void CameraControlSystem::Initialize()
{
    g_coordinator.AddEventListener(METHOD_LISTENER(Events::Window::INPUT, CameraControlSystem::InputListener));
}

void CameraControlSystem::Update(float& t_delta_time)
{
    for (auto& entity : entities)
    {
        auto& transform = g_coordinator.GetComponent<Transform>(entity);

        float speed = 20.0f;

        if (m_buttons.test(static_cast<std::size_t>(InputButtons::W)))
        {
            transform.location.z -= (t_delta_time * speed);
        }

        else if (m_buttons.test(static_cast<std::size_t>(InputButtons::S)))
        {
            transform.location.z += (t_delta_time * speed);
        }
        
        if (m_buttons.test(static_cast<std::size_t>(InputButtons::Q)))
        {
            transform.location.y += (t_delta_time * speed);
        }

        else if (m_buttons.test(static_cast<std::size_t>(InputButtons::E)))
        {
            transform.location.y -= (t_delta_time * speed);
        }

        if (m_buttons.test(static_cast<std::size_t>(InputButtons::A)))
        {
            transform.location.x -= (t_delta_time * speed);
        }

        else if (m_buttons.test(static_cast<std::size_t>(InputButtons::D)))
        {
            transform.location.x += (t_delta_time * speed);
        }
    }
}

void CameraControlSystem::InputListener(Event& t_event)
{
    m_buttons = t_event.GetParam<std::bitset<8>>(Events::Window::Input::INPUT);
}
