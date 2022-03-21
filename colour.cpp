#include <ostream>
#include "colour.hh"

using std::ostream;

void writeColour(ostream& out, colour pixelColour) {
  // add 0.5 bc int cast rounds down
  out << static_cast<int>((MAXCOLOUR + 0.5) * pixelColour.getX()) << ' '
      << static_cast<int>((MAXCOLOUR + 0.5) * pixelColour.getY()) << ' '
      << static_cast<int>((MAXCOLOUR + 0.5) * pixelColour.getZ()) << '\n';
}
