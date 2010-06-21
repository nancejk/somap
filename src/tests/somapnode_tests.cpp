#include <somapnode.hpp>
#include <memory>

// Sensible default values for node constructor
const xypair defPos = xypair(0, 0);
enum {defBins=10};

bool somapnode_default_constructor(int argc, char *argv[]) {
  std::auto_ptr<somapnode> 
    default_node(new (std::nothrow) somapnode(defPos, defBins));
  
  weights nodeWeights = default_node->getWeight();
  weights::iterator wi = nodeWeights.begin();
  
  
  // Check the number of bins, and node content
  while (wi != nodeWeights.end() && *wi >= 0 && *wi < MAXWEIGHT)
    wi++;

  // Check the position's set to what I constructed it with
  return wi == nodeWeights.end() && nodeWeights.size() == defBins &&
    default_node->getPosition() == defPos;
}
