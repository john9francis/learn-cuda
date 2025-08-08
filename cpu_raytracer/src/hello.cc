#include "hello.hh"
#include <iostream>

#include "color.hh"

void hello() {
  int imgHeight   = 256;
  int imgWidth = 256;

  //render

  std::cout << "P3\n" << imgWidth << " " << imgWidth << "\n255\n";

  for (int j=0; j<imgHeight  ; j++) {

    // progress bar
    std::clog << "\rScanlines remaining: " << (imgHeight   - j) << " " << std::flush;

    for (int i=0; i<imgWidth; i++) {
      color pixelColor = color(
        double(i)/(imgWidth-1),
        double(j)/(imgHeight  -1),
        0.0
      );

      write_color(std::cout, pixelColor);
    }
  }

  std::clog << "\rDone.                         \n";
}