#include "PerlinNoise.h"

PerlinNoise::PerlinNoise() {
    srand((unsigned) time(NULL));
    
    // Initialize permutation table
    for (int i = 0; i < GRID_SIZE; i++) {
        p[i] = i;
    }
    for (int i = 0; i < GRID_SIZE; i++) {
        int j = rand() % GRID_SIZE;
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        p[i + GRID_SIZE] = p[i];
    }

    // Generate gradient vectors
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            float angle = rand() * 2 * M_PI / RAND_MAX;
            grad_x[i][j] = cos(angle);
            grad_y[i][j] = sin(angle);
        }
    }
}

float PerlinNoise::noise(float x, float y, float z)
{
    // Calculate the grid cell coordinates and offsets
    int x0 = (int)floor(x);
    int y0 = (int)floor(y);
    int z0 = (int)floor(z);
    float dx = x - x0;
    float dy = y - y0;
    float dz = z - z0;

    // Calculate the fade curve values for x, y, z
    float u = fade(dx);
    float v = fade(dy);
    float w = fade(dz);

    // Calculate the hash values for the grid corners
    int A = p[x0] + y0;
    int AA = p[A] + z0;
    int AB = p[A + 1] + z0;
    int B = p[x0 + 1] + y0;
    int BA = p[B] + z0;
    int BB = p[B + 1] + z0;

    // Blend the noise values from the eight corners of the cube
    float res = lerp(w, lerp(v, lerp(u, grad(p[AA], dx, dy, dz),
                                     grad(p[BA], dx - 1, dy, dz)),
                             lerp(u, grad(p[AB], dx, dy - 1, dz),
                                  grad(p[BB], dx - 1, dy - 1, dz))),
                     lerp(v, lerp(u, grad(p[AA + 1], dx, dy, dz - 1),
                                  grad(p[BA + 1], dx - 1, dy, dz - 1)),
                          lerp(u, grad(p[AB + 1], dx, dy - 1, dz - 1),
                               grad(p[BB + 1], dx - 1, dy - 1, dz - 1))));
    // Rescale the output value to [0, 1]
    return (res + 1.0f) / 2.0f;
}

float PerlinNoise::fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float PerlinNoise::lerp(float t, float a, float b) {
    return a + t * (b - a);
}

float PerlinNoise::grad(int hash, float x, float y, float z) {
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
}