#include <iostream>
#include <assert.h>
#include <new>

bool somapconfig_tests(int, char**);

int main( int argc, char** argv ) {
  assert( somapconfig_tests(argc, argv) );

  return 0;
}
