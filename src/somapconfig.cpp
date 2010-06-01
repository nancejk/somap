#include <somapconfig.hpp>

somapconfig::somapconfig() :
  sidelength(-1), bincount(-1), fname("") 
{}

bool somapconfig::setFilename(std::string theFileName) {
  (*this).fname = boost::algorithm::trim_copy(theFileName);
  
  struct stat buffer;
  if( stat( fname.c_str(), &buffer ) == 0 ) return true;
  return false;
}

std::string somapconfig::getFileName() {
  return (*this).fname;
}

void somapconfig::setSideLength(int newSideLength) {
  (*this).sidelength = newSideLength;
}

void somapconfig::setSideLength(std::string newSideLength) {
  int final = -1;
  std::istringstream buffer(newSideLength);
  buffer >> final;
  this->setSideLength(final);
}

int somapconfig::getSideLength() {
  return (*this).sidelength;
}

void somapconfig::setBinCount(int newBinCount) {
  (*this).bincount = newBinCount;
}

void somapconfig::setBinCount(std::string newBinCount) {
  int final = -1;
  std::istringstream buffer(newBinCount);
  buffer >> final;
  this->setBinCount(newBinCount);
}

int somapconfig::getBinCount() {
  return (*this).bincount;
}

bool somapconfig::verify() {
  return ( ((*this).bincount != -1)
        && ((*this).sidelength != -1)
	&& ((*this).fname != "") );
}

somapconfig* somapconfig::digest(int argc, char** args) {
  somapconfig* newConfig;

  // OK, now use getopt to parse the options and set the appropriate
  // fields in the new configuration object.
  int cursor;
  while( (cursor = getopt(argc, args, "b:m:d:")) != -1 ) {
    switch(cursor) {
      case('b'):
	newConfig->setBinCount(optarg);
	break;
      case('d'):
	newConfig->setSideLength(optarg);
	break;
      case('m'):
	newConfig->setFilename(optarg);
	break;
      default:
	throw badConfig();
    }
  }

  return newConfig;
}
