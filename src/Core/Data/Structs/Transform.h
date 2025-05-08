#ifndef TRANSFORM_STRUCT_H
#define TRANSFORM_STRUCT_H

#include "../Types.h"

struct Transform
{
    
public:
    Transform() : location(0.f, 0.f, 0.f), rotation(0.f, 0.f, 0.f), scale(1.f, 1.f, 1.f)
    {
    }

    Transform(math::vec3f32 t_location, math::vec3f32 t_rotation, math::vec3f32 t_scale) : location(t_location), rotation(t_rotation), scale(t_scale)
    {
    }
    
    math::vec3f32 GetLocation() const {return location;}
    f32 GetLocationX() {return location.x;}
    f32 GetLocationY() {return location.y;}
    f32 GetLocationZ() {return location.z;}
    
    math::vec3f32 GetRotation() const {return rotation;}
    f32 GetRotationX() {return rotation.x;}
    f32 GetRotationY() {return rotation.y;}
    f32 GetRotationZ() {return rotation.z;}
    
    math::vec3f32 GetScale() const {return scale;}
    f32 GetScaleX() {return scale.x;}
    f32 GetScaleY() {return scale.y;}
    f32 GetScaleZ() {return scale.z;}
    
    void SetTransform(math::vec3f32 t_location, math::vec3f32 t_rotation, math::vec3f32 t_scale) {location = t_location; rotation = t_rotation; scale = t_scale;}
    
    void SetLocation(math::vec3f32 t_new_location) {location = t_new_location;}
    void SetLocationX(f32 t_new_x) {location.x = t_new_x;}
    void SetLocationY(f32 t_new_y) {location.y = t_new_y;}
    void SetLocationZ(f32 t_new_z) {location.z = t_new_z;}
    
    void SetRotation(math::vec3f32 t_new_rotation) {rotation = t_new_rotation;}
    void SetRotationX(f32 t_new_x) {rotation.x = t_new_x;}
    void SetRotationY(f32 t_new_y) {rotation.y = t_new_y;}
    void SetRotationZ(f32 t_new_z) {rotation.z = t_new_z;}
    
    void SetScale(math::vec3f32 t_new_scale) {scale = t_new_scale;}
    void SetScaleX(f32 t_new_x) {scale.x = t_new_x;}
    void SetScaleY(f32 t_new_y) {scale.y = t_new_y;}
    void SetScaleZ(f32 t_new_z) {scale.z = t_new_z;}
    
    math::vec3f32 location;
    math::vec3f32 rotation;
    math::vec3f32 scale;
};

#endif
