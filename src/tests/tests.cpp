#include <iostream>

// This tests that the default constructor does its job
// and sets sensible values in the fields.
bool somapconfig_default_constructor(int, char**);

// This does the same for the constructor that reads 
// argc and argv.
bool somapconfig_args_constructor(int, char**);

// Checks constructed random weights are within specified range, and
// that the bins and position are set correctly by default.
bool somapnode_default_constructor(int, char**);

// Checks that cartesian distance function works for input of the
// first 3 pythagorean triples.
bool somapfunctor_cartesian_distance(int, char**);

int main( int argc, char** argv ) {
  std::cout << "somapconfig_default_constructor " << 
    ( somapconfig_default_constructor(argc,argv) ? "PASS": "\aFAIL" ) <<
    std::endl;
  
  std::cout << "somapconfig_args_constructor " <<
    ( somapconfig_args_constructor(argc, argv) ? "PASS": "\aFAIL" ) <<
    std::endl;

  std::cout << "somapnode_default_constructor " <<
    ( somapnode_default_constructor(argc, argv) ? "PASS" : "\aFAIL" ) << 
    std::endl;

  std::cout << "somapfunctor_cartesian_distance " <<
    ( somapfunctor_cartesian_distance(argc, argv) ? "PASS" : "\aFAIL" ) <<    std::endl;

  return 0;
}
