#include <somapnode.hpp>
#include <memory>

// Sensible default values for node constructor
#define DEF_POS xypair(0, 0)
#define DEF_BINS 10

bool somapnode_default_constructor(int argc, char *argv[]) {
  std::auto_ptr<somapnode> 
    default_node(new (std::nothrow) somapnode(DEF_POS, DEF_BINS));
  
  weights nodeWeights = default_node->getWeight();
  weights::iterator wi = nodeWeights.begin();
  
  
  // Check the number of bins, and node content
  while (wi != nodeWeights.end() && *wi >= 0 && *wi < MAXWEIGHT)
    wi++;

  // Check the position's set to what I constructed it with
  return wi == nodeWeights.end() && nodeWeights.size() == DEF_BINS &&
    default_node->getPosition() == DEF_POS;
}
