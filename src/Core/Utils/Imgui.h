#ifndef IMGUI_CLASS_H
#define IMGUI_CLASS_H

#include "../../libraries/include/imgui/imgui.h"
#include "../../libraries/include/imgui/backends/imgui_impl_glfw.h"
#include "../../libraries/include/imgui/backends/imgui_impl_opengl3.h"
#include "../Window/Window.h"

class Imgui
{
public:
    static void Init(Window* t_window);
    static void Shutdown();

    static void BeginFrame();
    static void EndFrame();

    static bool WantCaptureMouse();

    static bool ShowDebugMenu(float t_ms_per_frame, unsigned short t_fps, unsigned int t_objects_count, unsigned int t_triangles_count);
};

#endif