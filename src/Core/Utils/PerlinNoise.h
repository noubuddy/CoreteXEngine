#ifndef PERLIN_NOISE_CLASS_H
#define PERLIN_NOISE_CLASS_H

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define GRID_SIZE 100
#define M_PI 3.14159265358979323846

class PerlinNoise
{
public:
    PerlinNoise();
    float Noise(float t_x, float t_y, float t_z);

private:
    float Fade(float t_t);
    float Lerp(float t_t, float t_a, float t_b);
    float Grad(int t_hash, float t_x, float t_y, float t_z);

    int m_p[GRID_SIZE * 2 + 1]{};
    float m_grad_x[GRID_SIZE][GRID_SIZE]{};
    float m_grad_y[GRID_SIZE][GRID_SIZE]{};
};

#endif