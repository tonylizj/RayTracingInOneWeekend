#include "vec3.hh"

using std::sqrt;
using std::ostream;

double randomDouble(double minVal, double maxVal);

vec3::vec3()
  : e{0, 0, 0} {}

vec3::vec3(double e0, double e1, double e2)
  : e{e0, e1, e2} {}

double vec3::getX() const {
    return e[0];
  }

double vec3::getY() const {
  return e[1];
}

double vec3::getZ() const {
  return e[2];
}

vec3& vec3::operator+=(const vec3& v) {
  e[0] += v.e[0];
  e[1] += v.e[1];
  e[2] += v.e[2];

  return *this;
}

vec3& vec3::operator-=(const vec3& v) {
  e[0] -= v.e[0];
  e[1] -= v.e[1];
  e[2] -= v.e[2];

  return *this;
}

vec3& vec3::operator*=(double t) {
  e[0] *= t;
  e[1] *= t;
  e[2] *= t;

  return *this;
}

vec3& vec3::operator/=(double t) {
  return *this *= (1/t);
}

vec3 vec3::operator+(const vec3& v) const{ 
  vec3 temp = *this;
  temp += v;
  return temp;
}

vec3 vec3::operator-(const vec3& v) const {
  vec3 temp = *this;
  temp -= v;
  return temp;
}

vec3 vec3::operator-() const {
  return -1 * *this;
}

vec3 vec3::operator*(double t) const {
  vec3 temp = *this;
  temp *= t;
  return temp;
}

vec3 vec3::operator*(const vec3& v) const {
  vec3 temp = *this;
  temp.e[0] *= v.e[0];
  temp.e[1] *= v.e[1];
  temp.e[2] *= v.e[2];
  return temp;
}

vec3 vec3::operator/(double t) const {
  vec3 temp = *this;
  temp /= t;
  return temp;
}

double vec3::length() const {
  return sqrt(this->lengthSquared());
}

double vec3::lengthSquared() const {
  return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

bool vec3::nearZero() const {
  const double s = 1e-8;
  return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

ostream& operator<<(ostream& os, const vec3& v) {
  return os << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

vec3 operator*(double t, const vec3& v) {
  return v * t;
}

double dot(const vec3& v1, const vec3& v2) {
  return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

vec3 cross(const vec3& v1, const vec3& v2) {
  return vec3{
    v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
    v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
    v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0],
  };
}

vec3 unitVector(const vec3& v) {
  return v / v.length();
}

vec3 randomVector(double minVal, double maxVal) {
  return vec3{randomDouble(minVal, maxVal), randomDouble(minVal, maxVal), randomDouble(minVal, maxVal)};
}

vec3 randomInUnitSphere() {
  while (true) {
    vec3 v = randomVector(-1, 1);
    if (v.lengthSquared() < 1) {
      return v;
    }
  }
}

vec3 randomInUnitDisc() {
  while (true) {
    vec3 v = vec3{randomDouble(-1, 1), randomDouble(-1, 1), 0};
    if (v.lengthSquared() < 1) {
      return v;
    }
  }
}

vec3 randomUnitVector() {
  return unitVector(randomInUnitSphere());
}

vec3 reflect(const vec3& v, const vec3& normal) {
  return v - 2 * dot(v, normal) * normal;
}

vec3 refract(const vec3& uv, const vec3& normal, double refractionRatio) {
  const double cosTheta = fmin(dot(-uv, normal), 1);
  const vec3 perpendicular = refractionRatio * (uv + cosTheta * normal);
  const vec3 parallel = -sqrt(fabs(1 - perpendicular.lengthSquared())) * normal;
  return perpendicular + parallel;
}
