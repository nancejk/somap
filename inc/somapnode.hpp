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

#endif
