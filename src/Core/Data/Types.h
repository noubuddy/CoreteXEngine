#ifndef CORTEX_TYPES_H
#define CORTEX_TYPES_H

#include <cstdint>
#include <glm/vec3.hpp>

///* Signed integer types *///
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

///* Unsigned integer types *///
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

///* Floating types *///
typedef float f32;
typedef double f64;

namespace math
{
    struct vec3f32
    {
        f32 x, y, z;
        
        vec3f32(f32 t_x = 0.0f, f32 t_y = 0.0f, f32 t_z = 0.0f) : x(t_x), y(t_y), z(t_z) {}

        glm::vec3 ToVec3() {return glm::vec3(x, y, z);}
    };
}

#endif