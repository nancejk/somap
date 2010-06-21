#include <somapfunctors.hpp>
#include <memory>

// we don't test position in this test, so it's fine if they're all
// the same
#define POS xypair(0, 0)
// do 2-d weights so that it's geometrically visualizable
#define NODESIZE 2


bool somapfunctor_cartesian_distance(int argc, char *argv[]) {

  typedef somapnode<cartesian_distance,linear_correction> def_somapnode;
  
  std::auto_ptr<cartesian_distance>
    cDist(new (std::nothrow) cartesian_distance());
  
  // Origin node
  std::auto_ptr<def_somapnode>
    n0(new (std::nothrow) def_somapnode(POS, NODESIZE));
  // Nodes for weight comparison
  std::auto_ptr<def_somapnode>
    n1(new (std::nothrow) def_somapnode(POS, NODESIZE));
  std::auto_ptr<def_somapnode>
    n2(new (std::nothrow) def_somapnode(POS, NODESIZE));
  std::auto_ptr<def_somapnode>
    n3(new (std::nothrow) def_somapnode(POS, NODESIZE));
  
  // Set the weights to form pythagorean triples when compared to the
  // origin.  Should give 5, 13, 25 respectively.
  weights w0, w1, w2, w3;
  // TODO: enter these in a more implementation independent manner
  // (this works only for std::vector's)
  w0.push_back(0), w0.push_back(0);
  w1.push_back(3), w1.push_back(4);
  w2.push_back(5), w2.push_back(12);
  w3.push_back(7), w3.push_back(24);
  n0->setWeight(w0), n1->setWeight(w1);
  n2->setWeight(w2), n3->setWeight(w3);

  return (*cDist)(*n0, *n1) == 5 &&
        (*cDist)(*n0, *n2) == 13 &&
        (*cDist)(*n0, *n3) == 25;
}
