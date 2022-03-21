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

  public:
    camera();

    ray getRay(double pixelsFromLeft, double pixelsFromBottom) const;
};

#endif
