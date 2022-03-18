#include <iostream>
#include "constants.hh"
#include "colour.hh"
#include "vec3.hh"
#include "ray.hh"

using std::cout;
using std::cerr;
using std::endl;
using std::flush;

bool hitSphere(const point3& center, double radius, const ray& r) {
  const vec3 CO = r.origin() - center;
  const double a = dot(r.direction(), r.direction());
  const double b = 2 * dot(CO, r.direction());
  const double c = dot(CO, CO) - radius * radius;
  const double disc = b * b - 4 * a * c;
  return disc >= 0;
}

colour rayColour(const ray& r) {
  if (hitSphere(point3{0, 0, -1}, 0.5, r)) {
    return colour{1, 0, 0};
  }
  const vec3 unitDirection = unitVector(r.direction());
  const double scaledRayHeight = 0.5 * (unitDirection.y() + 1);
  return (1 - scaledRayHeight) * WHITE + scaledRayHeight * BLUE;
}

ray generateRay(int pixelsFromLeft, int pixelsFromBottom) {
  const double u = static_cast<double>(pixelsFromLeft) / (IMAGEWIDTH - 1);
  const double v = static_cast<double>(pixelsFromBottom) / (IMAGEHEIGHT - 1);
  return ray{ORIGIN, (LOWERLEFTCORNER + u * HORIZONTAL + v * VERTICAL) - ORIGIN};
}

int main(void) {
  cout << "P3\n" << IMAGEWIDTH << ' ' << IMAGEHEIGHT << '\n' << MAXCOLOUR << '\n';

  for (int j = IMAGEHEIGHT - 1; j >= 0; --j) {
    cerr << "\rScanlines remaining: " << j + 1 << ' ' << flush;

    for (int i = 0; i < IMAGEWIDTH; ++i) {
      colour pixelColour = rayColour(generateRay(i, j));

      writeColour(cout, pixelColour);
    }
  }

  cerr << endl << "Done" << endl;
}
