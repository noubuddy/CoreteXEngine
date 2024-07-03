#ifndef INDICES_INL_H
#define INDICES_INL_H

std::vector<std::vector<GLuint>> indices =
{
    {
        // Front Face
        0, 1, 2,
        0, 3, 2,
    },
    {
        // Back Face
        4, 5, 6,
        4, 7, 6,
    },
    {
        // Top face
        8, 9, 10,
        8, 11, 10,
    },
    {
        // Bottom Face
        12, 13, 14,
        12, 15, 14,
        },
    {
        // Right Face
        16, 17, 18,
        16, 19, 18,
    },
    {
        // Left Face
        20, 21, 22,
        20, 23, 22,
    }
};

#endif