#ifndef CAMERA_CONTROL_SYSTEM_CLASS_H
#define CAMERA_CONTROL_SYSTEM_CLASS_H

#include "../ECS/System.h"
#include "../ECS/Event.h"

class CameraControlSystem : public System
{
public:
    void Initialize();

    void Update(float& t_delta_time);

private:
    std::bitset<8> m_buttons;

    void InputListener(Event& t_event);
};

#endif