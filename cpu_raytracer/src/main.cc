#include "vec3.hh"
#include <iostream>

#include "ray.hh"
#include "color.hh"

// tmp function
color GetRayColor(const ray& r) {
  // linear interpolation
  vec3 unitDirection = unit_vector(r.direction());
  double a = 0.5 * (unitDirection.getY() + 1.);
  return (1. - a) * color(1.,1.,1.) + a * color(0.5, 0.7, 1.);
}

int main(){
  // ideal aspect ratio is width / height
  double aspectRatio = 16. / 9.;

  // define image width and height (pixels)
  int imgWidth = 400;
  int imgHeight = int(imgWidth / aspectRatio);
  if (imgHeight < 1) imgHeight = 1;

  // and vieport width and height (doubles)
  // note it must be exactly equal to the pixel
  // aspect ratio for the pixels to be mapped correctly.
  double viewportHeight = 2.0;
  double viewportWidth = viewportHeight * double(imgWidth) / double(imgHeight);

  // define camera position
  auto focalLength = 1.0;
  point3 cameraCenter = point3(0,0,0);

  // the points at the edges of the screen
  // in order to get a pixel delta value
  vec3 u = vec3(viewportWidth, 0, 0);
  vec3 v = vec3(0, -viewportHeight, 0);
  vec3 dX = u / imgWidth;
  vec3 dY = v / imgHeight;

  // get top left vector (origin of drawing)
  point3 viewportUpperLeft = cameraCenter
    - vec3(0,0,focalLength) - u/2 - v/2;

  // get center of top left pixel
  point3 pixel00 = viewportUpperLeft + 0.5 * (dX + dY);

  // interesting... so we're going to shoot rays through center of each pixel

  // render
  std::cout << "P3\n" << imgWidth << " " << imgHeight << "\n255\n";

  for (int j=0; j<imgHeight; j++) {
    std::clog << "\rScanlines remaining: " << (imgHeight - j) << " " << std::flush;

    for (int i=0; i<imgWidth; i++) {
      point3 pixelCenter = pixel00 + (i * dX) + (j * dY);
      vec3 rayDirection = pixelCenter - cameraCenter;

      ray r(cameraCenter, rayDirection);

      color pixelColor = GetRayColor(r);
      write_color(std::cout, pixelColor);
    }
  }

  std::clog << "\rDone.                 \n";
}