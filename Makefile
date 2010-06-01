test_boost_libs := boost_unit_test_framework
test_flags := -Wno-write-strings
cxxsources := $(wildcard src/*.cpp tests/*.cpp)

default: check

check: $(cxxsources)
	g++ -c -o build/som_temp -Iinc -Wall src/somapconfig.cpp
	g++ -c -o build/test_temp -Iinc -Wall tests/tests.cpp $(test_flags)
	g++ -o bin/testing -Wall build/test_temp build/som_temp -lboost_unit_test_framework
	./bin/testing
