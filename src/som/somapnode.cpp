#include <somapnode.hpp>
#include <rng.hpp>

somapnode::somapnode(xypair pos, int len) :
  position(pos), dataStore(0), nodeID(0)
  // TODO initialize nodeID from a static map member
{
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

void somapnode::setWeight(weights input) {
  dataStore = input;
}

weights somapnode::getWeight() {
  return (*this).dataStore;
}

xypair somapnode::getPosition() {
  return (*this).position;
}
