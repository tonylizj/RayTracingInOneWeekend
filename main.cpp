#include <iostream>
#include "constants.hh"
#include "colour.hh"
#include "vec3.hh"
#include "ray.hh"
#include "hittable.hh"
#include "hittablelist.hh"
#include "sphere.hh"
#include "camera.hh"

using std::cout;
using std::cerr;
using std::endl;
using std::flush;

hittableList createWorld();
hittableList createBookFinalWorld();
double degToRad(double deg);

colour rayColour(const ray& r, const hittable& world, int depth) {
  hitRecord hit;

  if (depth <= 0) {
    return colour{0, 0, 0};
  }

  if (world.hit(r, 0.001, INFTY, hit)) {
    if (hit.getScattered()) {
      return hit.getAttenuation() * rayColour(hit.getScatteredRay(), world, depth - 1);
    }
    return colour{0, 0, 0};
  }

  const vec3 unitDirection = unitVector(r.getDirection());
  const double scaledRayHeight = 0.5 * (unitDirection.getY() + 1);
  return (1 - scaledRayHeight) * WHITE + scaledRayHeight * BLUE;
}

int main(void) {
  const hittableList world = createBookFinalWorld();

  const point3 position = point3{13, 2, 3};
  const point3 target = point3{0, 0, 0};
  const double vFOV = 20;
  const double aperture = 0.1;
  const double focalDistance = 10;
  const camera cam{position, target, vec3{0, 1, 0}, degToRad(vFOV), ASPECTRATIO, aperture, focalDistance};

  cout << "P3\n" << IMAGEWIDTH << ' ' << IMAGEHEIGHT << '\n' << MAXCOLOUR << '\n';

  for (int j = IMAGEHEIGHT - 1; j >= 0; --j) {
    cerr << "\rScanlines remaining: " << j + 1 << ' ' << flush;

    for (int i = 0; i < IMAGEWIDTH; ++i) {
      colour pixelColour{0, 0, 0};

      for (int s = 0; s < SAMPLES; ++s) {
        const ray ray = cam.getRay(i, j);
        pixelColour += rayColour(ray, world, BOUNCEDEPTH);
      }

      writeColour(cout, pixelColour);
    }
  }

  cerr << endl << "Done" << endl;
}
