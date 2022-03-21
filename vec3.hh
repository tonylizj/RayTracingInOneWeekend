#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
  private:
    double e[3];

  public:
    vec3();
    vec3(double e0, double e1, double e2);

    double getX() const;
    double getY() const;
    double getZ() const;

    vec3& operator+=(const vec3& v);
    vec3& operator-=(const vec3& v);
    vec3& operator*=(double t);
    vec3& operator/=(double t);

    vec3 operator+(const vec3& v) const;
    vec3 operator-(const vec3& v) const;
    vec3 operator-() const;
    vec3 operator*(double t) const;
    vec3 operator*(const vec3& v) const;
    vec3 operator/(double t) const;

    double length() const;
    double lengthSquared() const;
    bool nearZero() const;

    friend std::ostream& operator<<(std::ostream& os, const vec3& v);
    friend vec3 operator*(double t, const vec3& v);
    friend double dot(const vec3& v1, const vec3& v2);
    friend vec3 cross(const vec3& v1, const vec3& v2);
    friend vec3 unitVector(const vec3& v);
};

double dot(const vec3& v1, const vec3& v2);

vec3 cross(const vec3& v1, const vec3& v2);

vec3 unitVector(const vec3& v);

vec3 randomUnitVector();

vec3 reflect(const vec3& v, const vec3& normal);

using point3 = vec3;
using colour = vec3;

#endif
