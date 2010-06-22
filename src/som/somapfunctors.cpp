#include <somapfunctors.hpp>

somapComparisonFunctor::~somapComparisonFunctor() {
  //DO NOTHING
}

temporalCorrectionFunctor::~temporalCorrectionFunctor() {
  //DO NOTHING
}

spatialCorrectionFunctor::~spatialCorrectionFunctor() {
  //DO NOTHING
}

somapCorrectionFunctor::~somapCorrectionFunctor() {
  //DO NOTHING
}

double cartesian_distance::operator()(weights lhs, weights rhs) {
//TODO throw an exception if lhs.size != rhs.size
  double result(0.0);
  for(int i = 0; i < lhs.size(); i++) 
    {
      result += (lhs.at(i) - rhs.at(i))*(lhs.at(i) - rhs.at(i));
    }

  return sqrt( result );
}

cartesian_distance::~cartesian_distance() {
  //DO NOTHING
}

linear_correction::linear_correction(double newCorrectionStrength) :
  strength(newCorrectionStrength)
{ }

double linear_correction::operator()(double oldValue, double newValue) {
  //TODO daniel fix me please
  return 0.0;
}

linear_correction::~linear_correction() {
  // DO NOTHING
}
