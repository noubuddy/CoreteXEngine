#ifndef PHYCICS_CLASS
#define PHYCICS_CLASS
#include <cmath>

class Physics
{
public:
    float gravity = 9.8f; // m/s^2
    float jumpHeight = 2.0f; // meters
    float jumpVelocity = sqrt(2.0f * gravity * jumpHeight); // Initial velocity required to reach the desired jump height
    bool isJumping = false;

    
    
};

#endif