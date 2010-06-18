#include <somapfunctors.hpp>

double cartesian_distance::operator()(weights lhs, weights rhs) {
//TODO throw an exception if lhs.size != rhs.size
  double result(0.0);
  for(int i = 0; i < lhs.size(); i++) 
    {
      result += (lhs.at(i) - rhs.at(i))*(lhs.at(i) - rhs.at(i));
    }

  return sqrt( result );
}

somapComparisonFunctor::~somapComparisonFunctor() {
  //DO NOTHING
}

cartesian_distance::~cartesian_distance() {
  //DO NOTHING
}

linear_correction::linear_correction(double newCorrectionStrength) :
  correction_strength(newCorrectionStrength)
{ }

double linear_correction::operator()(weights input, double iterations, double distance) {
  //TODO daniel fix me please
  return 0.0;
}

linear_correction::~linear_correction() {
  // DO NOTHING
}
