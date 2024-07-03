#ifndef WORLD_MANAGER_CLASS
#define WORLD_MANAGER_CLASS
#include <vector>
#include <glm/vec3.hpp>
#include "PerlinNoise.h"

enum BlockType
{
    GRASS,
    WATER,
    SAND
};

struct BlockData
{
    glm::vec3 Position;
    BlockType Type;
};

class WorldManager
{
public:
    WorldManager();
    ~WorldManager();

    void GenerateWorldData();
    std::vector<BlockData>* GetWorldData();
    void CleanWorldData();

private:
    std::vector<BlockData>* WorldData;
    
};

#endif