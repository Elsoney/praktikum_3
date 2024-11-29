//
// Created by Peter Zdankin on 13.11.24.
//

#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "Vector3.hpp"

struct Sphere {
    double _radius;
    double _radius_squared;
    vec3 _center;
    vec3 _color;
    explicit Sphere(double radius, vec3 center, vec3 color);
};




#endif //SPHERE_HPP
