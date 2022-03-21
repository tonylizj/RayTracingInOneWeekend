#include "vec3.hh"
#include "hittable.hh"
#include "hittablelist.hh"
#include "sphere.hh"
#include <memory>

using std::make_shared;

hittableList createWorld() {
  hittableList world;

  auto ground = make_shared<sphere>(point3{0, -100.5, -1}, 100);
  auto sphere1 = make_shared<sphere>(point3{0, 0, -1}, 0.5);

  world.add(ground);
  world.add(sphere1);

  return world;
}
