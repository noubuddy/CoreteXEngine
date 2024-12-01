#include "Core/Engine.h"
#include "Core/Utils/Debug/Assertions/Assertions.h"

int main()
{
    Engine* engine = Engine::GetInstance();
    CHECK(engine != nullptr, "Engine instance has not been initialized!")

    engine->CreateDefaultGameWorld();

    engine->StartUp();

    return 0;
}
