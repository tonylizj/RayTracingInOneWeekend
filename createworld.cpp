#include <memory>
#include "lambertian.hh"
#include "metal.hh"
#include "dielectric.hh"
#include "vec3.hh"
#include "hittable.hh"
#include "hittablelist.hh"
#include "sphere.hh"

using std::make_shared;

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
