#include "metal.hh"
#include "hittable.hh"
#include "vec3.hh"

metal::metal(colour albedo, double fuzz)
  : material{}, albedo{albedo}, fuzz{fuzz < 1 ? fuzz : 1} {}

void metal::hit(const ray& r, hitRecord& record) const {
  vec3 reflected = reflect(unitVector(r.getDirection()), record.getNormal());
  record.setScatteredRay(ray{record.getPoint(), reflected + fuzz * randomInUnitSphere()});
  record.setAttenuation(albedo);
  record.setScattered(dot(record.getScatteredRay().getDirection(), record.getNormal()) > 0);
}
