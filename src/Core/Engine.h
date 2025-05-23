#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include <iostream>
#include <vector>

#include "GameObjects/ObjectBase.h"
#include "Graphics/Render/Renderer.h"
#include "Window/Window.h"
#include "../Game/World/WorldManager.h"
#include "Graphics/Camera/Camera.h"
#include "Graphics/Render/RenderPasses/DrawCubesRenderPass.h"
#include "Interfaces/IApplication.h"
#include "Utils/Imgui.h"
#include "Data/String.h"

static float delta_time;

class Engine : public IApplication
{
public:
    Engine() = default;
    ~Engine() override = default;
    
    bool StartUp() override;
    bool Initialize() override;
    bool ShutDown() override;

    void CreateDefaultGameWorld();
    static float GetDeltaTime();

private:
    
    void EngineLoop();
    
    void InitGraphics();
    void InitWindow();
    void InitRenderData();

    void UpdateScene();
    void UpdateTick(float& t_delta_time);
    void RenderFrame();

    bool ShouldStop();
    void OnTerminate();

    void CreateDefaultShaderProgram();

    void CreateDefaultCamera();
    void HandleInputs();
    
    Window* CreateDefaultWindow();
    Window* m_current_window;
    
    float CalculateDeltaTime(float& t_previous_time);

    DrawCubesRenderPass m_cube_render_pass;

    std::vector<Block*> m_game_objects;

    Renderer* m_renderer;
    Camera* m_camera;
};

#endif