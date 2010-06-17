#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

class somapfunctor {
 virtual double operator()(somapnode lhs, somapnode rhs) = 0;
public:
 virtual ~somapfunctor();
};

class cartesian_distance: public somapfunctor {
  virtual double operator()(somapnode lhs, somapnode rhs);
public:
  virtual ~cartesian_distance();
};
#endif
