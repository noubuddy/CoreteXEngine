#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include <iostream>
#include <vector>

#include "GameObjects/ObjectBase.h"
#include "Graphics/Render/Renderer.h"
#include "Window/Window.h"

static float delta_time;

class Engine
{
public:
    Engine();

    void StartUp();

    static float GetDeltaTime();

private:
    void EngineLoop();
    
    void InitGraphics();
    void InitWindow();

    void UpdateScene();
    void UpdateTick();
    void RenderFrame();

    bool ShouldStop();
    void OnTerminate();

    Window* CreateDefaultWindow();
    Window* m_current_window;
    
    float CalculateDeltaTime(float& previous_time);

    std::vector<ObjectBase*> m_game_objects;

    Renderer* m_renderer;
};

#endif