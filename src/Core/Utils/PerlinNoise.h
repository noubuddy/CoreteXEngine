#ifndef PERLIN_NOISE_CLASS_H
#define PERLIN_NOISE_CLASS_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define GRID_SIZE 200
#define M_PI 3.14159265358979323846

class PerlinNoise
{
public:
    PerlinNoise();
    float noise(float x, float y, float z);

private:
    float fade(float t);
    float lerp(float t, float a, float b);
    float grad(int hash, float x, float y, float z);

    int p[GRID_SIZE * 2 + 1]{};
    float grad_x[GRID_SIZE][GRID_SIZE]{};
    float grad_y[GRID_SIZE][GRID_SIZE]{};
};

#endif