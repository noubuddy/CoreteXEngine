#ifndef VERTICES_CLASS_H
#define VERTICES_CLASS_H

#include <vector>
#include <glad/glad.h>

enum CubeSide 
{
    front_face,
    back_face,
    top_face,
    bottom_face,
    right_face,
    left_face
};

class Vertices
{
public:
    
    static std::vector<GLfloat> GetVertices();

    static std::vector<GLfloat> GetVerticesBySide(CubeSide t_side);
    
    static const int vertices_amount_full = 192;

    static const int vertices_amount_side = 32;

private:

    static int GetFacesAmount();

    static int GetVerticesAmount(CubeSide t_side);
    
};
#endif