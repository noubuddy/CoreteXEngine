#include "Core/Application.h"
#include "Core/Engine.h"
#include "Core/Core.h"

int main()
{
    Application<Engine> engineApp;
    engineApp.Initialize();
    engineApp.StartUp();
    engineApp.ShutDown();

    return core::RESULT_SUCCESS;
}
