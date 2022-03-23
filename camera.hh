#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.hh"
#include "ray.hh"

class camera {
  private:
    point3 origin;
    point3 lowerLeftCorner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u, v, w;
    double lensRadius;

  public:
    camera(const point3& position, const point3& target, const vec3& up,
           double vFOV, double aspectRatio, double aperture, double focusDist);

    ray getRay(double pixelsFromLeft, double pixelsFromBottom) const;
};

#endif
