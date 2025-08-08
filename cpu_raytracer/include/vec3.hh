#pragma once

#include <cmath>
#include <iostream>
#ifdef DEBUG
  #include <stdexcept>
#endif

class vec3 {
public:
  // constructors
  vec3() : e{0,0,0} {}
  vec3(double x, double y, double z) : e{x, y, z} {}

  // getters
  double getX() const { return e[0]; };
  double getY() const { return e[1]; };
  double getZ() const { return e[2]; };

  // operator overloading
  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); };
  
  // note: these are now memory safe in DEBUG mode
  double operator[](int i) const {
    #ifdef DEBUG
      if (i < 0 || i > 2) {
        throw std::out_of_range("Vec3 index out of bounds");
      }
    #endif
    return e[i]; 
  };
  double& operator[](int i) { 
    #ifdef DEBUG
      if (i < 0 || i > 2) {
        throw std::out_of_range("Vec3 index out of bounds");
      }
    #endif
    return e[i]; 
  };

  // math operators
  vec3& operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }

  vec3& operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
  }

  vec3& operator/=(double t) {
    return *this *= 1/t;
  }

  double length() const {
    return std::sqrt(length_squared());
  }

  double length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
  }

  // the vec3 is just an array of 3 doubles
  double e[3];
};


// aliases for vec3 to make code more readable 
using point3 = vec3;

// Vector Utility Functions

// for printing
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
  return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// adding 2 vecs
inline vec3 operator+(const vec3& u, const vec3& v) {
  return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// subtracting 2 vecs
inline vec3 operator-(const vec3& u, const vec3& v) {
  return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// multiplying 2 vecs
inline vec3 operator*(const vec3& u, const vec3& v) {
  return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// multiplying vec by scalar
inline vec3 operator*(double t, const vec3& v) {
  return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// multiplying vec by scalar other way
inline vec3 operator*(const vec3& v, double t) {
  return t * v;
}

// divide vec by scalar
inline vec3 operator/(const vec3& v, double t) {
  return (1/t) * v;
}

// dot product, returns a scalar
inline double dot(const vec3& u, const vec3& v) {
  return u.e[0] * v.e[0]
       + u.e[1] * v.e[1]
       + u.e[2] * v.e[2];
}

// cross product, returns a vec
inline vec3 cross(const vec3& u, const vec3& v) {
  return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
              u.e[2] * v.e[0] - u.e[0] * v.e[2],
              u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// normalized
inline vec3 unit_vector(const vec3& v) {
  return v / v.length();
}