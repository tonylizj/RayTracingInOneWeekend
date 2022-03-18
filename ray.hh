#ifndef RAY_H
#define RAY_H

#include "vec3.hh"

class ray {
  point3 o;
  vec3 dir;

  public:

  ray();

  ray(const point3& o, const vec3& dir);

  point3 origin() const;

  vec3 direction() const;

  point3 at(const double t) const;
};

#endif
