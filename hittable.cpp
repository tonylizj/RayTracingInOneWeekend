#include "hittable.hh"
#include "ray.hh"

hitRecord::hitRecord()
  : point{}, normal{}, t{}, frontHit{} {}

point3 hitRecord::getPoint() const {
  return point;
}

vec3 hitRecord::getNormal() const {
  return normal;
}

double hitRecord::getT() const {
  return t;
}

void hitRecord::setPoint(point3 point) {
  this->point = point;
}

void hitRecord::setNormal(vec3 outboundNormal, const ray& ray) {
  frontHit = dot(ray.getDirection(), outboundNormal) < 0;
  this->normal = frontHit ? outboundNormal : -outboundNormal;
}

void hitRecord::setT(double t) {
  this->t = t;
}

