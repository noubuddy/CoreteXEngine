#ifndef VERTICES_CLASS_H
#define VERTICES_CLASS_H

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
    
    static GLfloat* GetVertices();

    static GLfloat* GetVerticesBySide(CubeSide Side);
    
    static const int VerticesAmount = 192;
};
#endif