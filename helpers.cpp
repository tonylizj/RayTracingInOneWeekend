#include <random>

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
