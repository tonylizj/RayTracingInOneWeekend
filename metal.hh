#ifndef METAL_H
#define METAL_H

#include "material.hh"
#include "colour.hh"

class metal : public material {
  private:
    colour albedo;
    double fuzz;

  public:
    metal(colour albedo, double fuzz);

    virtual void hit(const ray& r, hitRecord& rec) const override;
};

#endif
