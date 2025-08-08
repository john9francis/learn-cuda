#pragma once

#include "vec3.hh"

class ray {
public:
  ray(){}
  ray(const point3& origin, const vec3& direction) : _origin(origin), _direction(direction) {}

  point3 at(double t) const {
    // returns the point at time "t"
    return _origin + t * _direction;
  }

  // read only references
  const point3& origin() const { return _origin; }
  const vec3& direction() const { return _direction; }

private:
  point3 _origin;
  vec3 _direction;
};
