#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.hh"
#include "colour.hh"

class lambertian : public material {
  private:
    colour albedo;

  public:
    lambertian(colour albedo);

    virtual void hit(const ray& r, hitRecord& rec) const override;
};

#endif
