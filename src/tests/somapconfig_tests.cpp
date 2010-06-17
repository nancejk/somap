#include <somapconfig.hpp>
#include <new>
#include <sstream>
#include <memory>
#include <iostream> //TODO debug

bool somapconfig_default_constructor( int arg_count, char** arg_vector ) {
  std::auto_ptr<somapconfig> default_config ( new (std::nothrow) somapconfig() );
  return ( 
      default_config->getSideLength() == -1
      && default_config->getBinCount() == -1 
      && default_config->getFileName() == "" );
}

bool somapconfig_args_constructor( int arg_count, char** arg_vector ) {
  bool returnValue (false); 
  
  // Build the config object
  std::auto_ptr<somapconfig> config( new (std::nothrow) somapconfig(arg_count, arg_vector) );

  // Now check the arguments and verify that the configuration is what it
  // should be.
  for( int i = 1; i < arg_count; i ++ ) 
  {
    std::istringstream buffer;
    int temp;
    switch(arg_vector[i][1]) 
    {
      case('b'):
	returnValue = ( config->getBinCount() == atoi(arg_vector[i+1])); 
	break;
      case('m'):
	returnValue = ( config->getFileName() == arg_vector[i+1] );
	break;
      case('d'):
	returnValue = ( config->getSideLength() == atoi(arg_vector[i+1] ));
	break;
      default:
	break;
    }
  }

  return returnValue; 
}
