#ifndef METAL_H
#define METAL_H

#include "material.hh"
#include "colour.hh"

class metal : public material {
  private:
    colour albedo;

  public:
    metal(colour albedo);

    virtual void hit(const ray& r, hitRecord& rec) const override;
};

#endif
