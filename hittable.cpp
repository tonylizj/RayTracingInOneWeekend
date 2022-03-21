#include "hittable.hh"
#include "ray.hh"
#include <exception>

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

bool hitRecord::getFrontHit() const {
  return frontHit;
}

bool hitRecord::getScattered() const {
  return scattered;
}

ray hitRecord::getScatteredRay() const {
  return scatteredRay;
}

colour hitRecord::getAttenuation() const {
  return attenuation;
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

void hitRecord::setScattered(bool scattered) {
  this->scattered = scattered;
}

void hitRecord::setScatteredRay(const ray& scatteredRay) {
  this->scatteredRay = scatteredRay;
}

void hitRecord::setAttenuation(colour attenuation) {
  this->attenuation = attenuation;
}
