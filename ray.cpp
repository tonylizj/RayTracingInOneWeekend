#include "ray.hh"

ray::ray()
  : o{}, dir{} {};

ray::ray(const point3& o, const vec3& dir)
  : o{o}, dir{dir} {};

point3 ray::origin() const {
  return o;
}

vec3 ray::direction() const {
  return dir;
}

point3 ray::at(const double t) const {
  return o + t * dir;
}
