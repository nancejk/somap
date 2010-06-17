#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>

class somapfunctor {
 virtual double operator()(somapnode lhs, somapnode rhs) = 0;
};

class cartesian_distance: public somapfunctor {
  virtual double operator()(somapnode lhs, somapnode rhs);
};
#endif
