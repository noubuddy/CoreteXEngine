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
    PlayableCharacterBase(glm::vec3 t_location, glm::vec3 t_rotation, glm::vec3 t_scale);
    
};
