#ifndef __SOMAPNODE
#define __SOMAPNODE
#include <iostream>
#include <vector>
#include <memory>

#define MAXWEIGHT 1

// Most likely implementation
typedef double score;
typedef std::vector<double> weights;
typedef std::pair<int,int> xypair;

// forward class declaration
class somapComparisonFunctor;
class somapCorrectionFunctor;
class cartesian_distance;
class linear_correction;

// forward template class declaration
template <typename comparisonFunction = cartesian_distance, typename correctionFunction = linear_correction>
class somapnode;
#endif
