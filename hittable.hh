#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.hh"

class ray;

class hitRecord {
  private:
    point3 point;
    vec3 normal;
    double t;
    bool frontHit;

  public:
    hitRecord();

    point3 getPoint() const;
    vec3 getNormal() const;
    double getT() const;

    void setPoint(point3 point);
    void setNormal(vec3 outboundNormal, const ray& ray);
    void setT(double t);
};

class hittable {
  public:
    virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const = 0;
};

#endif
