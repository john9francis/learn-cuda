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

private:
  // the vec3 is just an array of 3 doubles
  double e[3];
};