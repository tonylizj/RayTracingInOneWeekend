#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <limits>
#include "vec3.hh"

const double INFTY = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;

const double ASPECTRATIO = 3.0 / 2.0;

const int IMAGEWIDTH = 1200;
const int IMAGEHEIGHT = static_cast<int>(IMAGEWIDTH / ASPECTRATIO);
const int MAXCOLOUR = 255;

const int SAMPLES = 500;
const int BOUNCEDEPTH = 50;

const colour WHITE = colour{1, 1, 1};
const colour BLUE = colour{0.5, 0.7, 1};

#endif
