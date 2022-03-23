#include "camera.hh"
#include "constants.hh"
#include "vec3.hh"

double randomDouble();

camera::camera(const point3& position, const point3& target, const vec3& up,
               double vFOV, double aspectRatio, double aperture, double focusDist) {
  const double viewportHeight = 2 * tan(vFOV / 2);
  const double viewportWidth = viewportHeight * aspectRatio;

  w = unitVector(position - target);
  u = unitVector(cross(up, w));
  v = unitVector(cross(w, u));

  origin = position;
  horizontal = viewportWidth * focusDist * u;
  vertical = viewportHeight * focusDist * v;
  lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - focusDist * w;

  lensRadius = aperture / 2;
}

ray camera::getRay(double pixelsFromLeft, double pixelsFromBottom) const {
  const vec3 randomPoint = this->lensRadius * randomInUnitDisc();
  const vec3 offset = u * randomPoint.getX() + v * randomPoint.getY();
  const double percentageFromLeft = static_cast<double>(pixelsFromLeft + randomDouble()) / (IMAGEWIDTH);
  const double percentageFromBottom = static_cast<double>(pixelsFromBottom + randomDouble()) / (IMAGEHEIGHT);
  return ray{this->origin + offset,
             (this->lowerLeftCorner + percentageFromLeft * this->horizontal + percentageFromBottom * this->vertical)
             - this->origin - offset};
}
