#include "metal.hh"
#include "hittable.hh"

metal::metal(colour albedo)
  : material{}, albedo{albedo} {}

void metal::hit(const ray& r, hitRecord& record) const {
  vec3 reflected = reflect(unitVector(r.getDirection()), record.getNormal());
  record.setScatteredRay(ray{record.getPoint(), reflected});
  record.setAttenuation(albedo);
  record.setScattered(dot(record.getScatteredRay().getDirection(), record.getNormal()) > 0);
}
