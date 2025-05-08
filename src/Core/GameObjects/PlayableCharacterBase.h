#pragma once
#include "ObjectBase.h"
#include "../Graphics/Camera/Camera.h"
#include "../Input/InputManager.h"

class PlayableCharacterBase : ObjectBase
{

private:
    Camera* m_player_camera;
    InputManager* m_input_profile;
    
public:
    PlayableCharacterBase();
    PlayableCharacterBase(math::vec3f32 t_location, math::vec3f32 t_rotation, math::vec3f32 t_scale);
    
};
