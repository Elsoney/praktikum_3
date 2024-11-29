//
// Created by Peter Zdankin on 13.11.24.
//

#include "Sphere.hpp"
Sphere::Sphere(double radius, vec3 center, vec3 color) {
    this->_radius = radius;
    this->_center = center;
    this->_color = color;
    this->_radius_squared = radius * radius;
}
