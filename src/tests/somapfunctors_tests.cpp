#include <somapfunctors.hpp>
#include <memory>

bool somapfunctor_cartesian_distance(int argc, char *argv[]) {


  cartesian_distance cDist;

  weights w0, w1, w2, w3;
  // Set the weights to form pythagorean triples when compared to the
  // origin.  Should give 5, 13, 25 respectively.
  w0.push_back(0), w0.push_back(0);
  w1.push_back(3), w1.push_back(4);
  w2.push_back(5), w2.push_back(12);
  w3.push_back(7), w3.push_back(24);

  return cDist(w0, w1) == 5 &&
    cDist(w0, w2) == 13 &&
    cDist(w0, w3) == 25;
}
