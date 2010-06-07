test_boost_libs := boost_unit_test_framework
test_flags := -Wno-write-strings

test_target := bin/unit_tests
som_sources := $(wildcard src/*.cpp)
test_sources := $(wildcard tests/*.cpp)

som_objects := $(som_sources:$.cpp=$.o) 
test_objects := $(test_sources:%.cpp=%.o) 

inc_dir := inc /usr/local/include/boost-1_38
inc := $(addprefix -I,$(inc_dir))

default: $(test_target)

$(test_target): $(test_objects) $(som_objects)
	@echo Linking $@...
	@$(CXX) -o $(test_target) $(addprefix build/,$(notdir $(test_objects)) $(notdir $(som_objects))) -l$(test_boost_libs)

%.o : %.cpp 
	@echo Compiling $< ... 
	@$(CXX) $(inc) -c $< -o $(addprefix build/,$(notdir $@)) $(test_flags) 
