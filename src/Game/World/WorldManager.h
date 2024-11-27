#ifndef WORLD_MANAGER_CLASS
#define WORLD_MANAGER_CLASS
#include <vector>
#include <glm/vec3.hpp>
#include "../../Core/Utils/PerlinNoise.h"
#include "../Block/Block.h"

class WorldManager
{
public:
    WorldManager();
    ~WorldManager();

    void GenerateWorldData();
    std::vector<Block*>* GetWorldData();
    void CleanWorldData();

private:
    std::vector<Block*>* WorldData;
    
};

#endif