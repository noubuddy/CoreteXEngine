#include "Core/Application.h"
#include "Core/Engine.h"
#include "Core/Core.h"
#include "Core/ECS/Coordinator.h"
#include "Core/Systems/CameraControlSystem.h"
#include "Core/Graphics/Camera/Camera.h"

Coordinator g_coordinator;

int main()
{
    //g_coordinator.AddEventListener(FUNCTION_LISTENER(Events::Window::QUIT, QuitHandler));
    g_coordinator.Init();

    ///* Components *///
    g_coordinator.RegisterComponent<Camera>();
    g_coordinator.RegisterComponent<Transform>();

    ///* Systems *///
    auto cameraControlSystem = g_coordinator.RegisterSystem<CameraControlSystem>();
    {
        Signature signature;
        signature.set(g_coordinator.GetComponentType<Camera>());
        signature.set(g_coordinator.GetComponentType<Transform>());
        g_coordinator.SetSystemSignature<CameraControlSystem>(signature);
    }
    cameraControlSystem->Initialize();

    Application<Engine> engineApp;
    
    if (!engineApp.Initialize())
        return core::RESULT_FAILURE;
    
    engineApp.StartUp();
    engineApp.ShutDown();

    return core::RESULT_SUCCESS;
}
