#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include <iostream>
#include <vector>

#include "GameObjects/ObjectBase.h"
#include "Graphics/Render/Renderer.h"
#include "Window/Window.h"
#include "../Game/World/WorldManager.h"
#include "Graphics/Camera/Camera.h"

static float delta_time;

class Engine
{
public:
    Engine();

    void StartUp();

    void CreateDefaultGameWorld();

    static float GetDeltaTime();

private:
    void EngineLoop();
    
    void InitGraphics();
    void InitWindow();
    void InitRenderData();

    void UpdateScene();
    void UpdateTick();
    void RenderFrame();

    bool ShouldStop();
    void OnTerminate();

    void CreateDefaultShaderProgram();

    void CreateDefaultCamera();
    void HandleInputs();
    
    Window* CreateDefaultWindow();
    Window* m_current_window;
    
    float CalculateDeltaTime(float& previous_time);

    std::vector<Block*> m_game_objects;

    Renderer* m_renderer;
    Camera* m_camera;
};

#endif