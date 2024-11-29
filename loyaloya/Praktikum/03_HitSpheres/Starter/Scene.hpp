#ifndef SCENE_HPP
#define SCENE_HPP

#include "Vector3.hpp"
#include "Sphere.hpp"
#include "Intersection.hpp"
#include "Ray.hpp"
#include <vector>  // Include this to use std::vector

struct Scene{
    // Vector<Sphere> is a dynamically growable list containing Spheres.
    std::vector<Sphere> _spheres;
    vec3 _backgroundColor;
    // epsilon is used to counteract float/double imprecisions
    double _epsilon = 0.000000001;

    explicit Scene(vec3 backgroundColor):_backgroundColor(backgroundColor){}
    Scene():_backgroundColor(vec3(0,0,0)){}  // Default background color

    void addSphere(Sphere object);  // Function to add a sphere to the scene
    const vec3 getBackgroundColor() const;  // Function to get the background color
    std::optional<Intersection> intersect(const Ray& ray) const;  // Ray-sphere intersection
    vec3 traceRay(const Ray& ray) const;  // Function to trace the ray and return color
};

#endif // SCENE_HPP
