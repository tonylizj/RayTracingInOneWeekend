#include <ostream>
#include "colour.hh"
#include "constants.hh"

using std::ostream;

void writeColour(ostream& out, colour pixelColour) {
  double r = pixelColour.getX();
  double g = pixelColour.getY();
  double b = pixelColour.getZ();

  r = sqrt(r / SAMPLES);
  g = sqrt(g / SAMPLES);
  b = sqrt(b / SAMPLES);

  // add 0.5 bc int cast rounds down
  out << static_cast<int>((MAXCOLOUR + 0.5) * r) << ' '
      << static_cast<int>((MAXCOLOUR + 0.5) * g) << ' '
      << static_cast<int>((MAXCOLOUR + 0.5) * b) << '\n';
}
