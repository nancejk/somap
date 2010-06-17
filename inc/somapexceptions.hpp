#ifndef __SOMAPEXCEPTIONS
#define __SOMAPEXCEPTIONS

#include <exception>

class badConfig: public std::exception {
  virtual const char* what(char arg);
};

#endif
