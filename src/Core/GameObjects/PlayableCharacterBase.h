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
    PlayableCharacterBase(glm::vec3 Location, glm::vec3 Rotation, glm::vec3 Scale);
    
};
