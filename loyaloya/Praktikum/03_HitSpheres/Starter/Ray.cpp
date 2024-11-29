//
// Created by Peter Zdankin on 13.11.24.
//
#include "Scene.hpp"
#include "Ray.hpp"

#include "Intersection.hpp"
#include "Sphere.hpp"

Ray::Ray(vec3 origin, vec3 direction) : _origin(origin), _direction(direction) {}

/* This is the task. Fill in the intersects method. A ray has an origin point and a direction.
 * A sphere has a center point and a radius, a radius_squared (hint), as well as a colour.
 * If the ray hits no object, return a {} (which indicates that there was no intersection).
 * If the ray hits an object, return a intersection.
 * To find out if a ray hits a sphere, you may (and should) use your math skills.
 * An intersection consists of the colour of the object hit by a ray, the surface normal (a unit_vector pointing from
 * the sphere center to the intersection point) as well as a "_t".
 * If you have an intersection, then _t solves the following:
 *  intersection_point = t * direction + origin
 *
 */
std::optional<Intersection> Ray::intersects(const Sphere& sphere) const {

    //optional might return or might not return intersection
    vec3 oc = _origin - sphere._center;
    double a = dot(_direction, _direction);
    double b = 2.0 * dot(oc, _direction);
    double c = dot(oc, oc) - sphere._radius_squared;

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return {}; // No intersection
    }

    double sqrt_discriminant = std::sqrt(discriminant);
    double t1 = (-b - sqrt_discriminant) / (2.0 * a);
    double t2 = (-b + sqrt_discriminant) / (2.0 * a);

    double t = (t1 > 0) ? t1 : t2;
    if (t < 0) {
        return {}; // Both intersections are behind the ray's origin
    }

    vec3 point = point_at(t);
    vec3 normal = unit_vector(point - sphere._center);
    return Intersection{sphere._color, normal, t};

  //  return {};
}



vec3 Ray::point_at(float t) const {
    return _origin + t * _direction;
}