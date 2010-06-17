#include <iostream>
#include <assert.h>
#include <new>

// This tests that the default constructor does its job
// and sets sensible values in the fields.
bool somapconfig_default_constructor(int, char**);

// This does the same for the constructor that reads 
// argc and argv.
bool somapconfig_args_constructor(int, char**);

int main( int argc, char** argv ) {
  assert( somapconfig_default_constructor(argc, argv) );
  assert( somapconfig_args_constructor(argc, argv) );

  return 0;
}
