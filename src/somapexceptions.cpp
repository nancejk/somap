#include <somapexceptions.hpp>

const char* badConfig::what(char arg) {
  return "Bad argument passed.";
}
