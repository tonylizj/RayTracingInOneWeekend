#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <limits>
#include "vec3.hh"

const double INFTY = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;

const double ASPECTRATIO = 16.0 / 9.0;

const int IMAGEWIDTH = 400;
const int IMAGEHEIGHT = static_cast<int>(IMAGEWIDTH / ASPECTRATIO);
const int MAXCOLOUR = 255;

const colour WHITE = colour{1, 1, 1};
const colour BLUE = colour{0.5, 0.7, 1};

const double VIEWPORTHEIGHT = 2;
const double VIEWPORTWIDTH = VIEWPORTHEIGHT * ASPECTRATIO;
const double FOCALLENGTH = 1;

const point3 ORIGIN = point3{0, 0, 0};
const vec3 HORIZONTAL = vec3{VIEWPORTWIDTH, 0, 0};
const vec3 VERTICAL = vec3{0, VIEWPORTHEIGHT, 0};
const vec3 FOCAL = vec3{0, 0, FOCALLENGTH};
const point3 LOWERLEFTCORNER = ORIGIN - HORIZONTAL / 2 - VERTICAL / 2 - FOCAL;

#endif
