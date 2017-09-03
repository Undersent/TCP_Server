include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

set(SOURCE_FILES main.cpp)

add_executable(runBasicTest main.cpp SampleTest.h
        SampleTest.cpp main.cpp)

target_link_libraries(runBasicTest gtest gtest_main)
#target_link_libraries(runBasicServerTest /usr/local/lib/libgtest.a)
#target_link_libraries(runBasicServerTest gtest gtest_main)
#target_link_libraries(runBasicServerTest src)