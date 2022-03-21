#include "camera.hh"
#include "constants.hh"

double randomDouble();

camera::camera() {
  const double aspectRatio = ASPECTRATIO;
  const double viewportHeight = 2;
  const double viewportWidth = viewportHeight * aspectRatio;
  const double focalLength = 1;

  origin = point3{0, 0, 0};
  horizontal = vec3{viewportWidth, 0, 0};
  vertical = vec3{0, viewportHeight, 0};
  const vec3 focal = vec3{0, 0, focalLength};
  lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - focal;
}

ray camera::getRay(double pixelsFromLeft, double pixelsFromBottom) const {
  const double u = static_cast<double>(pixelsFromLeft + randomDouble()) / (IMAGEWIDTH);
  const double v = static_cast<double>(pixelsFromBottom + randomDouble()) / (IMAGEHEIGHT);
  return ray{this->origin, (this->lowerLeftCorner + u * this->horizontal + v * this->vertical) - this->origin};
}
