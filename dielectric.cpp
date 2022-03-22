#include "dielectric.hh"
#include "hittable.hh"

double randomDouble();

dielectric::dielectric(double ir)
  : material{}, ir{ir} {}

double reflectance(double cos, double refractionRatio) {
  double r02 = ((1 - refractionRatio) / (1 + refractionRatio)) * ((1 - refractionRatio) / (1 + refractionRatio));
  return r02 + (1 - r02) * pow((1 - cos), 5);
}

void dielectric::hit(const ray& r, hitRecord& record) const {  
  record.setScattered(true);
  const double refractionRatio = record.getFrontHit() ? (1 / this->ir) : this->ir;
  const vec3 unitDirection = unitVector(r.getDirection());

  const double cosTheta = fmin(dot(-unitDirection, record.getNormal()), 1);
  const double sinTheta = sqrt(1 - cosTheta * cosTheta);

  const bool refractPossible = refractionRatio * sinTheta <= 1;
  vec3 direction = refractPossible && reflectance(cosTheta, refractionRatio) <= randomDouble()
                   ? refract(unitDirection, record.getNormal(), refractionRatio)
                   : reflect(unitDirection, record.getNormal());

  record.setScatteredRay(ray{record.getPoint(), direction});
  record.setAttenuation(colour{1, 1, 1});
}
