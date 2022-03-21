#include "lambertian.hh"
#include "hittable.hh"

lambertian::lambertian(colour albedo)
  : material{}, albedo{albedo} {}

void lambertian::hit(const ray& r, hitRecord& record) const {
  (void) r;
  
  record.setScattered(true);
  vec3 direction = record.getNormal() + randomUnitVector();
  if (direction.nearZero()) {
    direction = record.getNormal();
  }
  record.setScatteredRay(ray{record.getPoint(), direction});
  record.setAttenuation(albedo);
}
