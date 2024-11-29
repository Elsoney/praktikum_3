//
// Created by Peter Zdankin on 13.11.24.
//

#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP
#include "Vector3.hpp"


struct Intersection {
    vec3 _color;  // The color of the object that is hit by a Ray
    vec3 _normal; // The surface normal of the object that is hit by a ray
    double _t;    // A ray has an origin and a direction. If intersection = t * direction + origin, at which t did the ray hit the object?
    Intersection(vec3 color, vec3 normal, double t);
};

#endif //INTERSECTION_HPP
