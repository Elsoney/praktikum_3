cmake_minimum_required(VERSION 3.29)
project(03_HitSphere)

set(CMAKE_CXX_STANDARD 20)

add_executable(03_HitSphere main.cpp
        Vector3.hpp
        Vector3.cpp
        Sphere.hpp
        Sphere.cpp
        Ray.hpp
        Ray.cpp
        lodepng.h
        lodepng.cpp
        Intersection.hpp
        Intersection.cpp
        Camera.hpp
        Camera.cpp
        YourRayTracer.hpp
        YourRayTracer.cpp
        Screen.hpp
        Screen.cpp
        Scene.hpp
        Scene.cpp)
