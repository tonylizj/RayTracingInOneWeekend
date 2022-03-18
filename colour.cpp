#include "colour.hh"
#include <ostream>

using std::ostream;

void writeColour(ostream& out, const colour pixelColour) {
  out << static_cast<int>(MAXCOLOUR * pixelColour.x()) << ' '
      << static_cast<int>(MAXCOLOUR * pixelColour.y()) << ' '
      << static_cast<int>(MAXCOLOUR * pixelColour.z()) << '\n';
}
