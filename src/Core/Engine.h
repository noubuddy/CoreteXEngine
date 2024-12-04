#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include <iostream>
#include <vector>

#include "GameObjects/ObjectBase.h"
#include "Graphics/Render/Renderer.h"
#include "Window/Window.h"
#include "../Game/World/WorldManager.h"
#include "Graphics/Camera/Camera.h"
#include "Utils/Imgui.h"

/**
 * @brief Provides a pointer to the engine
 * @return Engine* 
 */
#define ENGINE Engine::GetInstance()

static float delta_time;

class Engine
{
public:
    Engine(const Engine&) = delete; // disable copy constructor
    Engine& operator=(const Engine&) = delete; // disable assignment operator

    static Engine* GetInstance()
    {
        if (!m_engine_instance)
        {
            m_engine_instance = new Engine();
        }
        return m_engine_instance;
    }

    void StartUp();

    void CreateDefaultGameWorld();

    static float GetDeltaTime();

private:
    
    Engine(){}

    static Engine* m_engine_instance;
    
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
    
    float CalculateDeltaTime(float& t_previous_time);

    std::vector<Block*> m_game_objects;

    Renderer* m_renderer;
    Camera* m_camera;
};

#endif