#include <somapnode.hpp>
#include <rng.hpp>

template <typename comparisonFunction, typename correctionFunction> 
class somapnode {
public:
  somapnode<comparisonFunction, correctionFunction>(xypair pos, int len);
  // update the node due to INPUT vector.  Needs to know if it was
  // highest scorer, or neighbour (conveyed by DISTANCE).  I
  // assumed the learning function is global visible.
  void learn(weights input, int distance);
  void setWeight(weights);
  weights getWeight();
  xypair getPosition();
  // defined this to test if it initializes correctly
  void printWeight();
private:
  // The function object that performs comparisons.
  std::auto_ptr<somapComparisonFunctor> comparator;

  // The function object that gets correction values.
  std::auto_ptr<somapCorrectionFunctor> corrector;

  // weights vector
  weights dataStore;
  
  // this node's position in the overall map
  xypair position;
  
  // IDs may be useful when looking for maximally excited node
  int nodeID;

  // somapfunctors need to access the private members of the
  // nodes.
  friend class cartesian_distance;
};

template <typename cmp, typename cor>
somapnode<cmp, cor>::somapnode (xypair pos, int len) :
  position(pos), 
  dataStore(0), 
  // TODO initialize nodeID from a static map member
  nodeID(0),
  comparator(new cmp),
  corrector(new cor)
{
  dataStore.reserve(len);
  
  // randomize the initial weights...
  RandomNumberEngine rand;
  for (int i=0; i < len; i++)
    dataStore.push_back(rand.GetUniformRandomReal(0, MAXWEIGHT));
}

template <typename cmp, typename cor>
void somapnode<cmp, cor>::printWeight() {

  weights::iterator wi = dataStore.begin();
  std::cout << "weights are:\n";
  while (wi != dataStore.end())
    std::cout << *wi++ << " ";
  std::cout << std::endl;
}

template <typename cmp, typename cor>
void somapnode<cmp, cor>::setWeight(weights input) {
  dataStore = input;
}

template <typename cmp, typename cor>
weights somapnode<cmp, cor>::getWeight() {
  return (*this).dataStore;
}

template <typename cmp, typename cor>
xypair somapnode<cmp, cor>::getPosition() {
  return (*this).position;
}
