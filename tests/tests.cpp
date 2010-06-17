#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE justatest

#include <boost/test/auto_unit_test.hpp>
#include <somapconfig.hpp>
#include <iostream>
#include <new>

// Make sure the default constructor does what it is
// supposed to do, which is set the fields to nonsense
// values.
BOOST_AUTO_TEST_CASE(default_constructor) {
  somapconfig* config = new somapconfig;
  BOOST_CHECK( config->getSideLength() == -1 );
  BOOST_CHECK( config->getFileName() == "" );
  BOOST_CHECK( config->getBinCount() == -1 );
  delete config;
}

BOOST_AUTO_TEST_CASE(config_factory) {
  char* test_argv[5];
  test_argv[0] = "something";
  test_argv[1] = "-m hello";
  test_argv[2] = "-b 1281";
  test_argv[3] = "-d 100";
  std::auto_ptr<somapconfig> config( new (std::nothrow) somapconfig(4,test_argv) );
  if( config.get() == NULL ) throw badConfig();

  BOOST_CHECK( config->getSideLength() == 100 );
  BOOST_CHECK( config->getBinCount()   == 1281 );
  BOOST_CHECK( config->getFileName()   == "hello" );
  BOOST_CHECK( config->verify()        == true );
}

