#include <memory>
#include "colour.hh"
#include "lambertian.hh"
#include "metal.hh"
#include "dielectric.hh"
#include "vec3.hh"
#include "hittable.hh"
#include "hittablelist.hh"
#include "sphere.hh"

using std::make_shared;

double randomDouble();
double randomDouble(double minVal, double maxVal);

hittableList createWorld() {
  hittableList world;

  const auto groundMaterial =       make_shared<lambertian>( colour{ 0.8, 0.8, 0.0});
  const auto centerMaterial =       make_shared<lambertian>( colour{ 0.1, 0.2, 0.5});
  const auto leftMaterial =         make_shared<dielectric>( 1.5);
  const auto rightMaterial =        make_shared<metal>(      colour{ 0.8, 0.6, 0.2}, 0.0);

  const auto ground =               make_shared<sphere>(     point3{  0.0, -100.5, -1.0},   100, groundMaterial);
  const auto center =               make_shared<sphere>(     point3{  0.0,    0.0, -1.0},   0.5, centerMaterial);
  const auto left =                 make_shared<sphere>(     point3{ -1.0,    0.0, -1.0},   0.5, leftMaterial  );
  const auto left1 =                make_shared<sphere>(     point3{ -1.0,    0.0, -1.0}, -0.45, leftMaterial  );
  const auto right =                make_shared<sphere>(     point3{  1.0,    0.0, -1.0},   0.5, rightMaterial );

  world.add(ground);
  world.add(center);
  world.add(left);
  world.add(left1);
  world.add(right);

  return world;
}

hittableList createBookFinalWorld() {
  hittableList world;

  const auto ground_material = make_shared<lambertian>(colour{0.5, 0.5, 0.5});
  world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

  for (int a = -11; a < 11; ++a) {
    for (int b = -11; b < 11; ++b) {
      const double choose_mat = randomDouble();
      const point3 center{a + 0.9 * randomDouble(), 0.2, b + 0.9 * randomDouble()};

      if ((center - point3{4, 0.2, 0}).length() > 0.9) {
        shared_ptr<material> sphere_material;

        if (choose_mat < 0.8) {
          // diffuse
          const colour albedo = randomColour() * randomColour();
          sphere_material = make_shared<lambertian>(albedo);
          world.add(make_shared<sphere>(center, 0.2, sphere_material));
        } else if (choose_mat < 0.95) {
          // metal
          const colour albedo = randomColour(0.5, 1);
          const double fuzz = randomDouble(0, 0.5);
          sphere_material = make_shared<metal>(albedo, fuzz);
          world.add(make_shared<sphere>(center, 0.2, sphere_material));
        } else {
          // glass
          sphere_material = make_shared<dielectric>(1.5);
          world.add(make_shared<sphere>(center, 0.2, sphere_material));
        }
      }
    }
  }

  const auto material1 = make_shared<dielectric>(1.5);
  world.add(make_shared<sphere>(point3{0, 1, 0}, 1.0, material1));

  const auto material2 = make_shared<lambertian>(colour{0.4, 0.2, 0.1});
  world.add(make_shared<sphere>(point3{-4, 1, 0}, 1.0, material2));

  const auto material3 = make_shared<metal>(colour{0.7, 0.6, 0.5}, 0.0);
  world.add(make_shared<sphere>(point3{4, 1, 0}, 1.0, material3));

  return world;
}
