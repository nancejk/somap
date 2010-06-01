#include <somapconfig.hpp>
#include <iostream>

int main(int argc, char** argv) {
  somapconfig* config;
  try{
    config = somapconfig::digest(argv);
  }
  catch(std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
