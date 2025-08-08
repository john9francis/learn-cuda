#include "hello.hh"
#include "vec3.hh"
#include <iostream>

int main(){
  // hello();

  vec3 vec(1,2,3);

  std::cout << "vec[0]: " << vec[0] << "\n";
  std::cout << "vec[3]: " << vec[3] << "\n";
}