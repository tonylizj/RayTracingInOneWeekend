#include "colour.hh"
#include <ostream>

using std::ostream;

void writeColour(ostream& out, const colour pixelColour) {
  // add 0.5 bc int cast rounds down
  out << static_cast<int>((MAXCOLOUR + 0.5) * pixelColour.x()) << ' '
      << static_cast<int>((MAXCOLOUR + 0.5) * pixelColour.y()) << ' '
      << static_cast<int>((MAXCOLOUR + 0.5) * pixelColour.z()) << '\n';
}
