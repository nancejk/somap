#ifndef __SOMAPNODE
#define __SOMAPNODE
#include <iostream>
#include <vector>
#include <memory>

enum {MAXWEIGHT=1};

// Most likely implementation
typedef double score;
typedef std::vector<double> weights;
typedef std::pair<int,int> xypair;

class somapnode {
public:
  somapnode(xypair pos, int len);
  // update the node due to INPUT vector.  Needs to know if it was
  // highest scorer, or neighbour (conveyed by DISTANCE).  I
  // assumed the learning function is global visible.
  void learn(weights input, int distance);
  double compare(weights input);
  void setWeight(weights);
  weights getWeight();
  xypair getPosition();
  // defined this to test if it initializes correctly
  void printWeight();
private:
  // weights vector
  weights dataStore;
  
  // this node's position in the overall map
  xypair position;
  
  // IDs may be useful when looking for maximally excited node
  int nodeID;
};
#endif
