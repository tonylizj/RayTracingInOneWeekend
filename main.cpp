#include <iostream>
#include "constants.hh"
#include "colour.hh"
#include "vec3.hh"
#include "ray.hh"
#include "hittable.hh"
#include "hittablelist.hh"
#include "sphere.hh"

using std::cout;
using std::cerr;
using std::endl;
using std::flush;

hittableList createWorld();

colour rayColour(const ray& ray, const hittable& world) {
  hitRecord hit;

  if (world.hit(ray, 0, INFTY, hit)) {
    return 0.5 * (hit.getNormal() + colour{1, 1, 1});
  }

  const vec3 unitDirection = unitVector(ray.getDirection());
  const double scaledRayHeight = 0.5 * (unitDirection.getY() + 1);
  return (1 - scaledRayHeight) * WHITE + scaledRayHeight * BLUE;
}

ray generateRay(int pixelsFromLeft, int pixelsFromBottom) {
  const double u = static_cast<double>(pixelsFromLeft) / (IMAGEWIDTH - 1);
  const double v = static_cast<double>(pixelsFromBottom) / (IMAGEHEIGHT - 1);
  return ray{ORIGIN, (LOWERLEFTCORNER + u * HORIZONTAL + v * VERTICAL) - ORIGIN};
}

int main(void) {
  hittableList world = createWorld();

  cout << "P3\n" << IMAGEWIDTH << ' ' << IMAGEHEIGHT << '\n' << MAXCOLOUR << '\n';

  for (int j = IMAGEHEIGHT - 1; j >= 0; --j) {
    cerr << "\rScanlines remaining: " << j + 1 << ' ' << flush;

    for (int i = 0; i < IMAGEWIDTH; ++i) {
      const colour pixelColour = rayColour(generateRay(i, j), world);
      writeColour(cout, pixelColour);
    }
  }

  cerr << endl << "Done" << endl;
}
