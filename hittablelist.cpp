#include "hittablelist.hh"

hittableList::hittableList()
  : hittable{} {}

hittableList::hittableList(shared_ptr<hittable> hittableObj)
  : hittable{} {
  this->add(hittableObj);
}

void hittableList::clear() {
  this->hittableObjs.clear();
}

void hittableList::add(shared_ptr<hittable> hittableObj) {
  this->hittableObjs.push_back(hittableObj);
}

bool hittableList::hit(const ray& ray, double tMin, double tMax, hitRecord& record) const {
  hitRecord temp;
  bool hasHit = false;
  double newTMax = tMax;

  for (const auto& obj : this->hittableObjs) {
    if (obj->hit(ray, tMin, newTMax, temp)) {
      hasHit = true;
      newTMax = temp.getT();
      record = temp;
    }
  }

  return hasHit;
}
