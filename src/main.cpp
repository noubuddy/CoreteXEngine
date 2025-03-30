#include "Core/Application.h"
#include "Core/Engine.h"
#include "Core/Core.h"

int main()
{
    Application<Engine> engineApp;
    
    if (!engineApp.Initialize())
        return core::RESULT_FAILURE;
    
    engineApp.StartUp();
    engineApp.ShutDown();

    return core::RESULT_SUCCESS;
}
