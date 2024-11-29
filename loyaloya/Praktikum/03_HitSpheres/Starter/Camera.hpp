//
// Created by Peter Zdankin on 13.11.24.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3.hpp"

struct Camera{
    vec3 _eyePoint; // from where do you look at the scene?
    vec3 _viewDir; // In which direction do you look?
    vec3 _upDir; // What direction is up for the camera?
    double _field_of_view; // narrow/wide

    // Here we have some constructors

    /* Instead of
     * Thing(int a, int b) {
     *  this->_a = a;
     *  this->_b = b;
     * }
     *
     * we can write
     * Thing(int a) : _a(a), _b(b) {}
     */
    Camera():_eyePoint(vec3(0,0,0)),_viewDir(vec3(0,0,1)),_upDir(vec3(0,1,0)), _field_of_view(60){}
    explicit Camera(const vec3 _eyePoint):_eyePoint(_eyePoint),_viewDir(vec3(0,0,1)),_upDir(vec3(0,1,0)), _field_of_view(60){}
    Camera(const vec3 _eyePoint, const vec3 _viewDir):_eyePoint(_eyePoint),_viewDir(_viewDir),_upDir(vec3(0,1,0)), _field_of_view(60){}
    Camera(const vec3 _eyePoint, const vec3 _viewDir, const vec3 _upDir):_eyePoint(_eyePoint),_viewDir(_viewDir),_upDir(_upDir), _field_of_view(60){}
    Camera(const vec3 _eyePoint, const vec3 _viewDir, const vec3 _upDir, const double _FoV):_eyePoint(_eyePoint),_viewDir(_viewDir),_upDir(_upDir), _field_of_view(_FoV){}

    void setEyePoint(vec3 eyePoint);
    void setViewDir(vec3 viewDir);
    void setUpDir(vec3 upDir);
    void setFoV(double FoV);
    void setLookAt(vec3 lookAt);

    const vec3& getEyePoint() const;
    const vec3& getViewDir() const;
    const vec3& getUpDir() const;
    double getFoV() const;

};

#endif //CAMERA_HPP
