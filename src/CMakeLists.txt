cmake_minimum_required(VERSION 3.8)
project(TCP_Server)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES TCPStreamFactory.cpp TCPStreamFactory.h TCPStreamData.cpp TCPStreamData.h
        AcceptorToTCPServer.cpp AcceptorToTCPServer.h Server.cpp ../AlgAndDataStructures/RSA.cpp ../AlgAndDataStructures/RSA.h)# ../Server_tests/basic_tests/SampleTest.cpp ../Server_tests/basic_tests/SampleTest.h ../Server_tests/basic_tests/main.cpp)
add_executable(TCP_Server ${SOURCE_FILES})