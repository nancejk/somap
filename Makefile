test_boost_libs := boost_unit_test_framework
test_flags := -Wno-write-strings -Weffc++ -pedantic

test_target := bin/unit_tests
som_sources := $(wildcard src/*.cpp)
test_sources := $(wildcard tests/*.cpp)

som_objects := $(som_sources:$.cpp=$.o) 
test_objects := $(test_sources:%.cpp=%.o) 

inc_dir := inc

default: $(test_target)

$(test_target): $(som_objects) $(test_objects)
	@echo LD $@
	@$(CXX) -o $(test_target) $(addprefix build/,$(notdir $(test_objects)) $(notdir $(som_objects))) -l$(test_boost_libs)

%.o : %.cpp 
	@echo CXX $< 
	@$(CXX) -I$(inc_dir) -c $< -o $(addprefix build/,$(notdir $@)) $(test_flags) 
