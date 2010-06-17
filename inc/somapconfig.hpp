#ifndef __SOMAPCONFIG
#define __SOMAPCONFIG

#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <somapexceptions.hpp>
#include <sstream>
#include <boost/algorithm/string/trim.hpp>

class somapconfig {
private:
  int sidelength;
  int bincount;
  std::string fname;
public:
  somapconfig ();
  somapconfig (int, char**);
  // This is the static factory method.
  static somapconfig* digest(int, char** );
  
  // Returns true if the filename provided
  // is already used on the filesystem.
  bool setFilename(std::string);
  std::string getFileName();

  // Sets the value of the sidelength parameter.
  // The parameter is public so it can be set simply, but this is a
  // convenience method mainly for use by getopt.
  void setSideLength(int);
  void setSideLength(std::string);
  int getSideLength();

  // Sets the bin count for the nodes.
  void setBinCount(int);
  void setBinCount(std::string);
  int getBinCount();

  // Verifies the configuration.
  bool verify();
};
#endif
