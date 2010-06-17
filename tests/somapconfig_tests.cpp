#include <somapnode.hpp>
#include <memory>

// reasonable values for position and number of bins
#define POS xypos(0, 0)
#define LEN 10

bool somapnode_default_constructor(int argc, char *argv[]) {
  std::auto_ptr<somapconfig> default_node ( new (std::nothrow)
					    somapnode(POS, LEN));
  int i=LEN;
  
