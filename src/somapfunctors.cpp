#include <somapfunctors.hpp>

double cartesian_distance::operator()(somapnode lhs, somapnode rhs) {
//TODO throw an exception if lhs.size != rhs.size
  double result(0.0);
  for(int i = 0; i < lhs.dataStore.size(); i++) 
  {
    result += (lhs.dataStore.at(i) - rhs.dataStore.at(i))*(lhs.dataStore.at(i) - rhs.dataStore.at(i));
  }

  return sqrt( result );
}
