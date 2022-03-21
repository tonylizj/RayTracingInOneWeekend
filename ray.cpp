#include "ray.hh"

ray::ray()
  : origin{}, direction{} {}

ray::ray(const point3& origin, const vec3& direction)
  : origin{origin}, direction{direction} {}

point3 ray::getOrigin() const {
  return origin;
}

vec3 ray::getDirection() const {
  return direction;
}

point3 ray::at(double t) const {
  return origin + t * direction;
}
