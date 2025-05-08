#include "WorldManager.h"

WorldManager::WorldManager() : m_world_data(nullptr)
{
    if (!m_world_data)
    {
        m_world_data = new std::vector<Block*>;
    }
}

WorldManager::~WorldManager()
{
    delete m_world_data;
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
                noiseValues[y][x] = noise.Noise(x * NOISE_SCALE, y * NOISE_SCALE, z * NOISE_SCALE);
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

            Block* block = new Block();
            block->SetLocation(math::vec3f32(x * CUBE_SIZE, afterDotValue * CUBE_SIZE, y * CUBE_SIZE));

            m_world_data->push_back(block);
        }
    }
}

std::vector<Block*>* WorldManager::GetWorldData()
{
    if (m_world_data)
        return m_world_data;
}

void WorldManager::CleanWorldData()
{
    if (!m_world_data)
        return;
    
    if (!m_world_data->empty())
        m_world_data->clear();
}
