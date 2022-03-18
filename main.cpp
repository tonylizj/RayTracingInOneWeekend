#include <iostream>
#include "imageConstants.hh"
#include "colour.hh"
#include "vec3.hh"

using std::cout;
using std::cerr;
using std::endl;
using std::flush;

int main(void) {
  cout << "P3\n" << IMAGEWIDTH << ' ' << IMAGEHEIGHT << '\n' << MAXCOLOUR << '\n';

  for (int i = 0; i < IMAGEHEIGHT; ++i) {
    cerr << "\rScanlines remaining: " << IMAGEHEIGHT - i << ' ' << flush;

    for (int j = 0; j < IMAGEWIDTH; ++j) {
      colour pixel{
        static_cast<double>(j) / (IMAGEWIDTH - 1),
        static_cast<double>(IMAGEWIDTH - 1 - i) / (IMAGEHEIGHT - 1),
        0.25
      };

      writeColour(cout, pixel);
    }
  }

  cerr << endl << "Done" << endl;
}
