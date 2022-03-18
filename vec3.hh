#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
  double e[3];

  public:

  vec3();

  vec3(const double e0, const double e1, const double e2);

  double x() const;

  double y() const;

  double z() const;

  vec3& operator+=(const vec3& v);

  vec3& operator-=(const vec3& v);

  vec3& operator*=(const double t);

  vec3& operator/=(const double t);

  vec3 operator+(const vec3& v) const;

  vec3 operator-(const vec3& v) const;

  vec3 operator*(const double t) const;

  vec3 operator*(const vec3& v) const;

  vec3 operator/(const double t) const;

  double length() const;

  double lengthSquared() const;

  friend std::ostream& operator<<(std::ostream& os, const vec3& v);

  friend vec3 operator*(const double t, const vec3& v);

  friend double dot(const vec3& v1, const vec3& v2);

  friend vec3 cross(const vec3& v1, const vec3& v2);

  friend vec3 unitVector(const vec3& v);
};

using point3 = vec3;
using colour = vec3;

#endif
