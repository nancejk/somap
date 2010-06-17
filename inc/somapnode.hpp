#include <vector>

// Most likely implementation
typedef double score;
typedef std::vector<double> weights;
typedef std::pair<int,int> xypair;

class somapnode {
public:
  /* I don't know how this functor stuff works... I'll assume it's
     globally visible for now, so I don't need to pass it to methods */
  somapnode(xypair pos, int len);
  // to grade INPUT vector against node's DATASTORE for similarity
  // score compare(weights input);
  // update the node due to INPUT vector.  Needs to know if it was
  // highest scorer, or neighbour (conveyed by DISTANCE).  I
  // assumed the learning function is global visible.
  void learn(weights input, int distance);
private:
  // weights vector
  weights dataStore;
  // this node's position in the overall map
  xypair position;
  // IDs may be useful when looking for maximally excited node
  int nodeID;
};
