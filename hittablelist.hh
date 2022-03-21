#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <vector>
#include <memory>
#include "hittable.hh"

using std::vector;
using std::shared_ptr;

class hittableList : public hittable {
  private:
    vector<shared_ptr<hittable>> hittableObjs;

  public:
    hittableList();
    hittableList(shared_ptr<hittable> hittableObj);

    void clear();

    void add(shared_ptr<hittable> hittableObj);

    virtual bool hit(const ray& ray, double tMin, double tMax, hitRecord& record) const override;
};

#endif
