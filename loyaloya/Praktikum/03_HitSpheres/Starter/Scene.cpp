//
// Created by Peter Zdankin on 13.11.24.
//


#include "Scene.hpp"

void Scene::addSphere(Sphere object){
    _spheres.push_back(object);
}


const vec3 Scene::getBackgroundColor() const{
    return _backgroundColor;
}

std::optional<Intersection> Scene::intersect(const Ray& ray) const{

    std::optional<Intersection> result = {};

    for(auto& object: _spheres){
        std::optional<Intersection> i = ray.intersects(object);
        if( !i.has_value()){
            continue;
        }

        if(!result.has_value() || i->_t < result->_t){
            result = i;
        }
    }

    return result;
}


vec3 Scene::traceRay(const Ray& ray) const {

    std::optional<Intersection> intersection = intersect(ray);
    //Nothing hit
    if (!intersection.has_value()) {
        return _backgroundColor;
    }
    return intersection->_color;
}