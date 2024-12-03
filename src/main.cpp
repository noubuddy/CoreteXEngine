#include "Core/Engine.h"
#include "Core/Utils/Debug/Assertions/Assertions.h"

int main()
{
    Engine* engine = ENGINE;
    CHECK(engine != nullptr, "Engine instance has not been initialized!")

    engine->CreateDefaultGameWorld();

    engine->StartUp();

    return 0;
}
