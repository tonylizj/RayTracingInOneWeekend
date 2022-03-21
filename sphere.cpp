#include "sphere.hh"
#include "vec3.hh"
#include "ray.hh"
#include <memory>

sphere::sphere()
  : hittable{}, center{}, radius{} {}

sphere::sphere(point3 center, double radius, shared_ptr<material> mat)
  : hittable{}, center{center}, radius{radius}, mat{mat} {}

bool sphere::hit(const ray& ray, double tMin, double tMax, hitRecord& record) const {
  const vec3 CO = ray.getOrigin() - center;
  const double a = ray.getDirection().lengthSquared();
  const double halfb = dot(CO, ray.getDirection());
  const double c = CO.lengthSquared() - radius * radius;
  const double sqrtDisc = sqrt(halfb * halfb - a * c);

  double root = (-halfb - sqrtDisc) / a;
  if (!(root >= tMin && root <= tMax)) {
    root = (-halfb + sqrtDisc) / a;
    if (!(root >= tMin && root <= tMax)) {
      return false;
    }
  }

  record.setT(root);
  record.setPoint(ray.at(record.getT()));
  record.setNormal((record.getPoint() - this->center) / this->radius, ray);

  mat->hit(ray, record);

  return true;
}
