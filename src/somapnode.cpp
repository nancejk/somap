#include <somapnode.hpp>
#include <rng.hpp>

#define MAXWEIGHT 1

somapnode::somapnode(xypair pos, int len) {
  position = pos;
  
  // randomize the initial weights...
  RandomNumberEngine rand;
  rand.GetUniformRandomReal(0, MAXWEIGHT);
  //
}
