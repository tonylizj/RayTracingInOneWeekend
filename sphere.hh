#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hh"
#include "material.hh"
#include <memory>

using std::shared_ptr;

class sphere : public hittable {
  private:
    point3 center;
    double radius;
    shared_ptr<material> mat;

  public:
    sphere();
    sphere(point3 center, double radius, shared_ptr<material> mat);

    virtual bool hit(const ray& ray, double tMin, double tMax, hitRecord& record) const override;
};

#endif
