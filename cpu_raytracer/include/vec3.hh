#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>

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
  
  // note: these are now memory safe
  double operator[](int i) const {
    if (i > 2 || i < 0) {
      throw std::out_of_range("Tried to access vector index above 2 or below 0");
    }
    return e[i]; 
  };
  double& operator[](int i) { 
    if (i > 2 || i < 0) {
      throw std::out_of_range("Tried to access vector index above 2 or below 0");
    }
    return e[i]; 
  };

private:
  // the vec3 is just an array of 3 doubles
  double e[3];
};