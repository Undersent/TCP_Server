include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicServerTests
        SampleTest.cpp)
include_directories(/usr/local/include)
target_link_libraries(runBasicServerTest /usr/local/lib/libgtest.a)
target_link_libraries(runBasicServerTest gtest gtest_main)
target_link_libraries(runBasicServerTest src)