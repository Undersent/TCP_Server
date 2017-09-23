cmake_minimum_required(VERSION 3.3)

#add_subdirectory(lib/googletest)
#add_subdirectory(lib/googlemock)
add_subdirectory(lib)
#include_directories(lib/googletest/include) #nie wiem czy potrzebne
add_subdirectory(basic_tests)
add_subdirectory(mocks)
set(CMAKE_CXX_STANDARD 14)