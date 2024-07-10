#include "WorldManager.h"

WorldManager::WorldManager() : WorldData(nullptr)
{
    if (!WorldData)
    {
        WorldData = new std::vector<BlockData>;
    }
}

WorldManager::~WorldManager()
{
}

void WorldManager::GenerateWorldData()
{
    CleanWorldData();
    
    // Constants for the grid size and cube size
    const float CUBE_SIZE = 1.f;
    const float THRESHOLD = 0.4f;

    // Constants for the noise parameters
    const float NOISE_SCALE = 0.05f;

    // Initialize the Perlin noise object
    PerlinNoise noise;
    std::vector<std::vector<float>> noiseValues(GRID_SIZE, std::vector<float>(GRID_SIZE));

    // Fill noiseValues array
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            for (int z = 0; z < GRID_SIZE; ++z)
            {
                noiseValues[y][x] = noise.noise(x * NOISE_SCALE, y * NOISE_SCALE, z * NOISE_SCALE);
            }
        }
    }

    // Generate world array
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            float noiseValue = noiseValues[y][x];

            // get first digit after the dot
            float afterDotValue = static_cast<int>(std::floor(std::fabs(noiseValue) * 10)) % 10;

            BlockData blockData{};
            blockData.Position = glm::vec3(x * CUBE_SIZE, afterDotValue * CUBE_SIZE, y * CUBE_SIZE);

            if (noiseValue > THRESHOLD)
            {
                blockData.Type = GRASS;
            }
            else if (noiseValue > 0.37 && noiseValue < THRESHOLD)
            {
                blockData.Type = SAND;
            }
            else
            {
                blockData.Type = WATER;
            }

            WorldData->push_back(blockData);
        }
    }
}

std::vector<BlockData>* WorldManager::GetWorldData()
{
    return WorldData;
}

void WorldManager::CleanWorldData()
{
    if (!WorldData->empty())
    {
        WorldData->clear();
    }
}
