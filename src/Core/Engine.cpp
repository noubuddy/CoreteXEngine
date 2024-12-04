#include "Engine.h"

Engine* Engine::m_engine_instance = nullptr;

void Engine::StartUp()
{
    InitGraphics();
    InitWindow();

    CreateDefaultShaderProgram();
    InitRenderData();
    CreateDefaultCamera();
    Imgui::Init(m_current_window);

    m_renderer->GetShaderProgram()->Activate();
    m_renderer->EnableDepthTest(true);
    m_renderer->SetVSyncFreq(0);
    
    // should be always at the end
    EngineLoop();
}

void Engine::CreateDefaultGameWorld()
{
    // VERY BAD!!! TEMPORARY SOLUTION!!!
    
    WorldManager worldManager;
    worldManager.GenerateWorldData();
    std::vector<Block*>* worldData = worldManager.GetWorldData();

    for(Block* block : *worldData)
    {
        m_game_objects.push_back(block);
    }
}

float Engine::GetDeltaTime()
{
    return delta_time;
}

void Engine::EngineLoop()
{
    float previousTime = (float)glfwGetTime();
    
    while (!ShouldStop())
    {
        delta_time = CalculateDeltaTime(previousTime);
        // std::cout << "Delta time: " << GetDeltaTime() << "\n"; // just for test

        Imgui::BeginFrame();
        HandleInputs();
        
        UpdateScene();

        // game logic here
        UpdateTick();

        RenderFrame();

        Imgui::EndFrame();
        m_current_window->SwapBuffers();
        m_current_window->PollEvents();
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

    // m_renderer->EnableDepthTest(true);
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

void Engine::InitRenderData()
{
    std::vector<std::string> imagePaths =
{
        "resources/block.jpg", "resources/block.jpg", "resources/block.jpg",
        "resources/block.jpg", "resources/block-top.jpg", "resources/block.jpg"
    };
    
    TextureArray textureArray(imagePaths, GL_TEXTURE_2D_ARRAY, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    textureArray.TexUnit(*m_renderer->GetShaderProgram(), "texArray", 0);
    textureArray.Bind();

    std::vector<GLfloat> v = Vertices::GetVertices();
    std::vector<GLuint> i = Indices::GetIndices();

    m_renderer->PushRenderData(v, i, textureArray);
}

void Engine::UpdateScene()
{
    glClearColor(0.29f, 0.66f, 0.87f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::UpdateTick()
{
    if (!m_renderer->GetShaderProgram())
    {
        std::cout << "Shader program is null!\n";
    }
    
    for (Block* object : m_game_objects)
    {
        if (!object)
        {
            continue;
        }

        if (object->IsRenderable())
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(glm::mat4(1.0f), object->GetLocation());
            
            m_camera->Matrix(80.f, 0.1f, 300.0f, *m_renderer->GetShaderProgram(), "camMatrix", model);

            m_renderer->Render();
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
    Imgui::Shutdown();
    m_current_window->DestroyWindow();
    
    glfwTerminate();
}

void Engine::CreateDefaultShaderProgram()
{
    if (!m_renderer)
        return;

    m_renderer->SetShaderProgram(new Shader("src/Core/Graphics/Shader/Shaders/default.vert", "src/Core/Graphics/Shader/Shaders/default.frag"));
}

void Engine::CreateDefaultCamera()
{
    m_camera = new Camera(1920, 1080, glm::vec3(10.0f, 100.0f, 10.0f));
}

void Engine::HandleInputs()
{
    if (!m_camera)
        return;

    m_camera->Inputs(m_current_window->GetCurrentWindow());
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

float Engine::CalculateDeltaTime(float& t_previous_time)
{
    const float currentTime = (float)glfwGetTime();
    const float delta = currentTime - t_previous_time;
    t_previous_time = currentTime;
    
    return delta;
}