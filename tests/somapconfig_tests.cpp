#include <somapconfig.hpp>
#include <new>
#include <memory>
#include <assert.h>

bool somapconfig_default_constructor( int arg_count, char** arg_vector ) {
  std::auto_ptr<somapconfig> default_config ( new (std::nothrow) somapconfig() );
  return ( 
      default_config->getSideLength() == -1
      && default_config->getBinCount() == -1 
      && default_config->getFileName() == "" );
}

bool somapconfig_args_constructor( int arg_count, char** arg_vector ) {
  std::auto_ptr<somapconfig> config( new (std::nothrow) somapconfig(arg_count, arg_vector) );
  return true;
}

