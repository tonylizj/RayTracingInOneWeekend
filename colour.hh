#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>
#include "constants.hh"

void writeColour(std::ostream& out, colour pixelColour);

colour randomColour();

colour randomColour(double minVal, double maxVal);

#endif
