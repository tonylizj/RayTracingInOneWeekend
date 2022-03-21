#ifndef MATERIAL_H
#define MATERIAL_H

class hitRecord;
class ray;

class material {
  public:
    virtual void hit(const ray& r, hitRecord& record) const = 0;
};

#endif
