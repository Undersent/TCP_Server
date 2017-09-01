cmake_minimum_required(VERSION 3.8)
project(TCP_Server)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp TCPStreamFactory.cpp TCPStreamFactory.h TCPStreamData.cpp TCPStreamData.h ConnectorToTCPServer.cpp ConnectorToTCPServer.h AcceptorToTCPServer.cpp AcceptorToTCPServer.h)
add_executable(TCP_Server ${SOURCE_FILES})