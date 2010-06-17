#include <somapconfig.hpp>
#include <somapnode.hpp>
#include <iostream>
#include <new>

// I've deleted your boost tests, Jared, because they were fucked.

int main(int argc, char *argv[])
{
  somapnode n(xypair(0, 0), 10);
  n.printWeight();
  return 0;
}
