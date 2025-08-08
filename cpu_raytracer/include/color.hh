#pragma once

#include "vec3.hh"
#include <iostream>

// color class, extends vec3 class

using color = vec3;

void write_color(std::ostream& out, const color& pixelColor) {
  // ensure pixelColor is normalized between 0 and 1
  vec3 normalizedColor = unit_vector(pixelColor);

  auto r = normalizedColor.getX();
  auto g = normalizedColor.getY();
  auto b = normalizedColor.getZ();

  // rescale the 0,1 to 0,255
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  // write 
  out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}