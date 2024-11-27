#include "Engine.h"

Engine::Engine()
{
}

void Engine::StartUp()
{
    InitGraphics();
    InitWindow();

    m_renderer->EnableDepthTest(true);
    CreateDefaultShaderProgram();
    CreateDefaultCamera();
    
    // should be always at the end
    EngineLoop();
}

void Engine::CreateDefaultGameWorld()
{
    // VERY BAD!!! TEMPORARY SOLUTION!!!
    
    WorldManager world_manager;
    world_manager.GenerateWorldData();
    std::vector<Block*>* world_data = world_manager.GetWorldData();

    for(Block* block : *world_data)
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
    float m_previous_time = (float)glfwGetTime();

    InitRenderData();
    
    while (!ShouldStop())
    {
        delta_time = CalculateDeltaTime(m_previous_time);
        std::cout << "Delta time: " << GetDeltaTime() << "\n"; // just for test

        HandleInputs();
        
        UpdateScene();

        // game logic here
        UpdateTick();

        RenderFrame();

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
    std::vector<std::string> image_paths =
{
        "resources/block.jpg", "resources/block.jpg", "resources/block.jpg",
        "resources/block.jpg", "resources/block-top.jpg", "resources/block.jpg"
    };
    
    TextureArray texture_array(image_paths, GL_TEXTURE_2D_ARRAY, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    texture_array.TexUnit(*m_renderer->GetShaderProgram(), "texArray", 0);
    texture_array.Bind();

    std::vector<GLfloat> v = Vertices::GetVertices();
    std::vector<GLuint> i = Indices::GetIndices();

    m_renderer->PushRenderData(v, i, texture_array);
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
            // model = glm::translate(glm::mat4(1.0f), object->GetLocation());
            model = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, 0.f));
            
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
    m_current_window->DestroyWindow();
    
    glfwTerminate();
}

void Engine::CreateDefaultShaderProgram()
{
    if (!m_renderer)
        return;


    m_renderer->SetShaderProgram(new Shader("src/Core/Graphics/Shader/Shaders/default.vert", "src/Core/Graphics/Shader/Shaders/default.frag"));
    // Shader** shader_program = m_renderer->GetShaderProgram();
    // *shader_program = new Shader("src/Core/Graphics/Shader/Shaders/default.vert", "src/Core/Graphics/Shader/Shaders/default.frag");
}

void Engine::CreateDefaultCamera()
{
    m_camera = new Camera(1920, 1080, glm::vec3(0.0f, 0.0f, 0.0f));
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

float Engine::CalculateDeltaTime(float& previous_time)
{
    const float current_time = (float)glfwGetTime();
    const float delta = current_time - previous_time;
    previous_time = current_time;
    
    return delta;
}