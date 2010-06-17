#include <somapnode.hpp>
#include <rng.hpp>

#define MAXWEIGHT 1

somapnode::somapnode(xypair pos, int len) {
  position = pos;
  dataStore.reserve(len);
  
  // randomize the initial weights...
  RandomNumberEngine rand;
  for (int i=0; i < len; i++)
    dataStore.push_back(rand.GetUniformRandomReal(0, MAXWEIGHT));
}

void somapnode::printWeight() {

  weights::iterator wi = dataStore.begin();
  std::cout << "weights are:\n";
  while (wi != dataStore.end())
    std::cout << *wi++ << " ";
  std::cout << std::endl;
}
