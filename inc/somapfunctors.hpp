#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

class somapFunctorBase {
  public:
    virtual ~somapFunctorBase();
};

class somapComparisonFunctor : public somapFunctorBase {
  public:
    virtual double operator()(weights, weights) = 0;
    virtual ~somapComparisonFunctor();
};

class temporalCorrectionFunctor : public somapFunctorBase {
  protected:
    double time_constant;
  public:
    virtual double operator()(double) = 0;
    virtual ~temporalCorrectionFunctor();
};

class spatialCorrectionFunctor : public somapFunctorBase {
  protected:
    double attenuation_length;
  public:
    virtual double operator()(double) = 0;
    virtual ~spatialCorrectionFunctor();
};

class somapCorrectionFunctor : public somapFunctorBase {
  public:
    virtual double operator()(double, double) = 0;
    virtual ~somapCorrectionFunctor();
};

class cartesian_distance: public somapComparisonFunctor {
  public:
    virtual double operator()(weights, weights);
    virtual ~cartesian_distance();
};

class linear_correction: public somapCorrectionFunctor {
  private:
    double strength;
  public:
    linear_correction(double);
    virtual double operator()(double, double);
    virtual ~linear_correction();
};

class space_step_function: public spatialCorrectionFunctor {
  private:
    double cutoff;
  public:
    space_step_function(double);
    double operator()(double);
    ~space_step_function();
};

class time_step_function: public temporalCorrectionFunctor {
  private:
    double cutoff;
  public:
    time_step_function(double);
    double operator()(double);
    ~time_step_function();
};

class correctionComposition: public somapFunctorBase {
  private:
    std::auto_ptr<temporalCorrectionFunctor> t;
    std::auto_ptr<spatialCorrectionFunctor> s;
  public:
    correctionComposition(temporalCorrectionFunctor*, spatialCorrectionFunctor*);
    virtual double operator()(double,double);
};

#endif
