cmake_minimum_required(VERSION 3.3)



add_subdirectory(src/network)
add_subdirectory(Server_tests)

#add_subdirectory(AlgAndDataStructures)

#add_subdirectory(Server_tests/lib/googletest)
#include_directories(Server_tests/lib/googletest/googletest/include)
#include_directories(Server_tests/lib/googletest/googlemock/include)
#target_link_libraries(TCP_Server gtest gtest_main)