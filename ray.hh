#ifndef RAY_H
#define RAY_H

#include "vec3.hh"

class ray {
  private:
    point3 origin;
    vec3 direction;

  public:
    ray();
    ray(const point3& origin, const vec3& direction);

    point3 getOrigin() const;
    vec3 getDirection() const;

    point3 at(double t) const;
};

#endif
