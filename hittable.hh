#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec3.hh"
#include "ray.hh"

class hitRecord {
  private:
    point3 point;
    vec3 normal;
    double t;
    bool frontHit;
    bool scattered;
    ray scatteredRay;
    colour attenuation;

  public:
    hitRecord();

    point3 getPoint() const;
    vec3 getNormal() const;
    double getT() const;
    bool getFrontHit() const;
    bool getScattered() const;
    ray getScatteredRay() const;
    colour getAttenuation() const;

    void setPoint(point3 point);
    void setNormal(vec3 outboundNormal, const ray& ray);
    void setT(double t);
    void setScattered(bool scattered);
    void setScatteredRay(const ray& scatteredRay);
    void setAttenuation(colour attenuation);
};

class hittable {
  public:
    virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& record) const = 0;
};

#endif
