#include "Engine.h"

Engine::Engine()
{
}

void Engine::StartUp()
{
    InitGraphics();
    InitWindow();
    
    // should be always at the end
    EngineLoop();
}

float Engine::GetDeltaTime()
{
    return delta_time;
}

void Engine::EngineLoop()
{
    float m_previous_time = (float)glfwGetTime();

    while (!ShouldStop())
    {
        delta_time = CalculateDeltaTime(m_previous_time);
        std::cout << "Delta time: " << GetDeltaTime() << "\n"; // just for test

        UpdateScene();

        // game logic here
        UpdateTick();

        RenderFrame();

        m_current_window->SwapBuffers();
    }

    OnTerminate();
}

void Engine::InitGraphics()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!m_renderer)
    {
        m_renderer = new Renderer();
    }

    m_renderer->EnableDepthTest(true);
}

void Engine::InitWindow()
{
    m_current_window = CreateDefaultWindow();
    if (!m_current_window)
    {
        // TODO: add check
        return;
    }
}

void Engine::UpdateScene()
{
    glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::UpdateTick()
{
    for (ObjectBase* object : m_game_objects)
    {
        if (!object)
        {
            continue;
        }

        if (object->IsRenderable())
        {
            
        }

        object->Update();
    }
}

void Engine::RenderFrame()
{
}

bool Engine::ShouldStop()
{
    if (m_current_window->WindowShouldClose())
    {
        return true;
    }

    return false;
}

void Engine::OnTerminate()
{
    m_current_window->DestroyWindow();
    
    glfwTerminate();
}

Window* Engine::CreateDefaultWindow()
{
    Window* window = new Window(1920, 1080, "CoreteXngin", nullptr, nullptr);
    if (!window->CreateWindow())
    {
        // TODO: add check
        return nullptr;
    }

    window->SetAsCurrentWindow();

    return window;
}

float Engine::CalculateDeltaTime(float& previous_time)
{
    const float current_time = (float)glfwGetTime();
    const float delta = current_time - previous_time;
    previous_time = current_time;
    
    return delta;
}