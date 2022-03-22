#include "camera.hh"
#include "constants.hh"

double randomDouble();

camera::camera(const point3& position, const point3& target, const vec3& up, double vFOV, double aspectRatio) {
  const double viewportHeight = 2 * tan(vFOV / 2);
  const double viewportWidth = viewportHeight * aspectRatio;

  const vec3 focalVec = unitVector(position - target);
  const vec3 horizontalVec = unitVector(cross(up, focalVec));
  const vec3 verticalVec = unitVector(cross(focalVec, horizontalVec));

  origin = position;
  horizontal = viewportWidth * horizontalVec;
  vertical = viewportHeight * verticalVec;
  lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - focalVec;
}

ray camera::getRay(double pixelsFromLeft, double pixelsFromBottom) const {
  const double u = static_cast<double>(pixelsFromLeft + randomDouble()) / (IMAGEWIDTH);
  const double v = static_cast<double>(pixelsFromBottom + randomDouble()) / (IMAGEHEIGHT);
  return ray{this->origin, (this->lowerLeftCorner + u * this->horizontal + v * this->vertical) - this->origin};
}
