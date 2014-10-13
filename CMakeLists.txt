cmake_minimum_required(VERSION 2.8.3)
project(friction_models)

# Include a custom cmake file for TinyXML
#find_package()

# BUILD
include_directories(include
	)

## TESTS
add_executable(coulomb_test
	test/coulomb_friction_model_test.cpp
	)

target_link_libraries(coulomb_test
	)

