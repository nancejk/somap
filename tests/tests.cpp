#include <iostream>
#include <new>

// This tests that the default constructor does its job
// and sets sensible values in the fields.
bool somapconfig_default_constructor(int, char**);

// This does the same for the constructor that reads 
// argc and argv.
bool somapconfig_args_constructor(int, char**);

int main( int argc, char** argv ) {
  std::cout << "somapconfig_default_constructor " << 
    ( somapconfig_default_constructor(argc,argv) ? "PASS": "FAIL" ) <<
    std::endl;
  
  std::cout << "somapconfig_args_constructor " <<
    ( somapconfig_args_constructor(argc, argv) ? "PASS": "FAIL" ) <<
    std::endl;

  return 0;
}
