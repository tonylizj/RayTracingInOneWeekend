#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "material.hh"
#include "colour.hh"

class dielectric : public material {
  private:
    double ir;

  public:
    dielectric(double ir);

    virtual void hit(const ray& r, hitRecord& rec) const override;
};

#endif
