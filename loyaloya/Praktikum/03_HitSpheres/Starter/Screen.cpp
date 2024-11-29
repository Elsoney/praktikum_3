//
// Created by Peter Zdankin on 13.11.24.
//


#include "Screen.hpp"

#include <iostream>
#include <fstream>
#include "lodepng.h"

void printHeader(std::ofstream& ppmFile, const unsigned int width, const unsigned int height) {
    ppmFile << "P3" << std::endl; // Magic Number, we're doing a pixelmap here
    ppmFile << width << " " << height << std::endl;   // We need to specify width/height
    ppmFile << "255" << std::endl;    // Maximum value
}


void write_color(std::ostream& out, const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Translate the [0,1] component values to the byte range [0,255].
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}


void Screen::setPixel(uint64_t  x, uint64_t  y, vec3 c){
    _data[_width*y + x] = c;
}
uint64_t  Screen::getWidth() const{
    return _width;
}
uint64_t  Screen::getHeight() const{
    return _height;
}
void Screen::clear(){
    for(auto& i: _data){
        i = {0,0,0};
    }
}

void Screen::saveAsPPM(const char *filename) {
    std::ofstream ppmFile(filename);
    printHeader(ppmFile, _width ,_height);
    for( int y = 0; y < _height; y++) {
        for( int x = 0; x < _width; x++) {
            write_color(ppmFile, _data[_width*y + x]);
        }
        ppmFile << "\n";
    }
}

void Screen::saveAsPNG(const char *filename) {
    std::vector<unsigned char> temp_data;
    for(auto pixel: _data) {
        temp_data.push_back(int(255.999 * pixel.x())); // Red
        temp_data.push_back(int(255.999 * pixel.y())); // Green
        temp_data.push_back(int(255.999 * pixel.z())); // Blue
        temp_data.push_back(int(255.0));               // Alpha
    }
    unsigned error = lodepng::encode(filename, temp_data, _width, _height);
    std::cout << error << std::endl;

}
/*
#include "Scene.hpp"

// Add a sphere to the scene
void Scene::addSphere(Sphere object) {
    _spheres.push_back(object);
}

// Get the background color of the scene
const vec3 Scene::getBackgroundColor() const {
    return _backgroundColor;
}

// Find the intersection of a ray with the spheres in the scene
std::optional<Intersection> Scene::intersect(const Ray& ray) const {
    for (auto& object : _spheres) {
        auto intersection = ray.intersects(object);  // Assuming Ray has intersects with Sphere
        if (intersection) {
            return intersection;  // Return the first intersection found
        }
    }
    return {};  // Return nothing if no intersection was found
}

// Trace a ray and return the color of the object hit (or background color if no hit)
vec3 Scene::traceRay(const Ray& ray) const {
    auto intersection = intersect(ray);
    if (intersection) {
        // If the ray hits an object, return the object's color
        return intersection->getColor();
    }
    // Otherwise, return the background color
    return _backgroundColor;

}
*/