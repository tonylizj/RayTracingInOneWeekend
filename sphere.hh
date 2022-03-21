#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hh"

class sphere : public hittable {
  private:
    point3 center;
    double radius;

  public:
    sphere();
    sphere(point3 center, double radius);

    virtual bool hit(const ray& ray, double tMin, double tMax, hitRecord& record) const override;
};

#endif
