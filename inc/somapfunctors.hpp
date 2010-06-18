#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

class somapfunctor {
  // dansci-- commented next 3 lines out as i think () should be
  // public
//  virtual double operator()(somapnode lhs, somapnode rhs) = 0;
// public:
//  virtual ~somapfunctor();
  // <dansci>
public:
  virtual double operator()(somapnode lhs, somapnode rhs) = 0;
 virtual ~somapfunctor();
  // </dansci>
};

class cartesian_distance: public somapfunctor {
  // dansci-- again, i think () should be public.  commented next 3
  // lines.
//   virtual double operator()(somapnode lhs, somapnode rhs);
// public:
//   virtual ~cartesian_distance();
  // <dansci>
public:
  virtual double operator()(somapnode lhs, somapnode rhs);
  virtual ~cartesian_distance();
  // </dansci>
};
#endif
