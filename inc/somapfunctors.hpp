#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

class somapfunctor {
public:
 virtual double operator()(somapnode lhs, somapnode rhs) = 0;
 virtual ~somapfunctor();
};

class cartesian_distance: public somapfunctor {
public:
  virtual double operator()(somapnode lhs, somapnode rhs);
  virtual ~cartesian_distance();
};
#endif
