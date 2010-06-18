#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

class somapComparisonFunctor {
  public:
    virtual double operator()(weights, weights) = 0;
    virtual ~somapComparisonFunctor();
};

class cartesian_distance: public somapComparisonFunctor {
  public:
    virtual double operator()(weights, weights);
    virtual ~cartesian_distance();
};

class somapCorrectionFunctor {
  public:
    virtual double operator()(weights, double, double) = 0;
    virtual ~somapCorrectionFunctor();
};

class linear_correction: public somapCorrectionFunctor {
  private:
    double correction_strength;
  public:
    linear_correction(double);
    virtual double operator()(weights, double, double);
    virtual ~linear_correction();
};
#endif
