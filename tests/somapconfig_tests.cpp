#include <somapconfig.hpp>
#include <new>
#include <memory>
#include <assert.h>

// This constructs an somapconfig object from
// the arguments and makes sure that the values
// are sane.

bool somapconfig_tests( int arg_count, char** arg_vector ) {
  std::auto_ptr<somapconfig> default_config ( new (std::nothrow) somapconfig() );
  return ( default_config->getSideLength() == -1 );
}
