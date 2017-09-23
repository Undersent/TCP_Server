include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_STANDARD 14)
add_executable(runBasicMockTest main.cpp RestAPIMock.cpp)

target_link_libraries(runBasicMockTest gmock gmock_main)