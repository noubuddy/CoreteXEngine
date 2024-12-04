#include "PerlinNoise.h"

PerlinNoise::PerlinNoise() {
    srand((unsigned) time(NULL));
    
    // Initialize permutation table
    for (int i = 0; i < GRID_SIZE; i++) {
        m_p[i] = i;
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        int j = rand() % GRID_SIZE;
        int temp = m_p[i];
        m_p[i] = m_p[j];
        m_p[j] = temp;
        m_p[i + GRID_SIZE] = m_p[i];
    }

    // Generate gradient vectors
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            float angle = rand() * 2 * M_PI / RAND_MAX;
            m_grad_x[i][j] = cos(angle);
            m_grad_y[i][j] = sin(angle);
        }
    }
}

float PerlinNoise::Noise(float t_x, float t_y, float t_z)
{
    // Calculate the grid cell coordinates and offsets
    int x0 = (int)floor(t_x);
    int y0 = (int)floor(t_y);
    int z0 = (int)floor(t_z);
    float dX = t_x - x0;
    float dY = t_y - y0;
    float dZ = t_z - z0;

    // Calculate the fade curve values for x, y, z
    float u = Fade(dX);
    float v = Fade(dY);
    float w = Fade(dZ);

    // Calculate the hash values for the grid corners
    int a = m_p[x0] + y0;
    int aa = m_p[a] + z0;
    int ab = m_p[a + 1] + z0;
    int b = m_p[x0 + 1] + y0;
    int ba = m_p[b] + z0;
    int bb = m_p[b + 1] + z0;

    // Blend the noise values from the eight corners of the cube
    float res = Lerp(w, Lerp(v, Lerp(u, Grad(m_p[aa], dX, dY, dZ),
                                     Grad(m_p[ba], dX - 1, dY, dZ)),
                             Lerp(u, Grad(m_p[ab], dX, dY - 1, dZ),
                                  Grad(m_p[bb], dX - 1, dY - 1, dZ))),
                     Lerp(v, Lerp(u, Grad(m_p[aa + 1], dX, dY, dZ - 1),
                                  Grad(m_p[ba + 1], dX - 1, dY, dZ - 1)),
                          Lerp(u, Grad(m_p[ab + 1], dX, dY - 1, dZ - 1),
                               Grad(m_p[bb + 1], dX - 1, dY - 1, dZ - 1))));
    // Rescale the output value to [0, 1]
    return (res + 1.0f) / 2.0f;
}

float PerlinNoise::Fade(float t_t) {
    return t_t * t_t * t_t * (t_t * (t_t * 6 - 15) + 10);
}

float PerlinNoise::Lerp(float t_t, float t_a, float t_b) {
    return t_a + t_t * (t_b - t_a);
}

float PerlinNoise::Grad(int t_hash, float t_x, float t_y, float t_z) {
    int h = t_hash & 15;
    float u = h < 8 ? t_x : t_y;
    float v = h < 4 ? t_y : h == 12 || h == 14 ? t_x : t_z;
    return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
}