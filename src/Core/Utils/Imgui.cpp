#include "Imgui.h"

void Imgui::Init(Window* t_window)
{
    if (!t_window)
    {
        // TODO: add check and log
        return;
    }
    
    if (!t_window->GetCurrentWindow())
    {
        // TODO: add check and log
        return;
    }   
    
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch
    
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(t_window->GetCurrentWindow(), true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();
}

void Imgui::Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Imgui::BeginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow();
}

void Imgui::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

bool Imgui::WantCaptureMouse()
{
    return ImGui::GetIO().WantCaptureMouse;
}
