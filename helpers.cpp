#include <random>
#include "constants.hh"

static std::random_device rd;
static std::mt19937 gen{rd()};

double randomDouble() {
  std::uniform_real_distribution<double> dist{0, 1};
  return dist(gen);
}

double randomDouble(double minVal, double maxVal) {
  std::uniform_real_distribution<double> dist{minVal, maxVal};
  return dist(gen);
}

double degToRad(double deg) {
  return deg * PI / 180.0;
}
