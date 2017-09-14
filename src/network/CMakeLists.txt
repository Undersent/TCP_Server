cmake_minimum_required(VERSION 3.8)
project(TCP_Server)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
set(SOURCE_FILES TCPStreamFactory.cpp TCPStreamFactory.h TCPStreamData.cpp TCPStreamData.h
        AcceptorToTCPServer.cpp AcceptorToTCPServer.h Server.cpp ../../AlgAndDataStructures/RSA.cpp
        ../../AlgAndDataStructures/RSA.h ../multithreading/Thread.cpp ../multithreading/Thread.h
        ../data_transfer/WorkerQueue.h ../data_transfer/WorkItem.h ConnectionHandler.h
        ../../AlgAndDataStructures/Queue.h ../../AlgAndDataStructures/RSA.cpp ../../AlgAndDataStructures/RSA.h ../../AlgAndDataStructures/TernarySearchTree.cpp ../../AlgAndDataStructures/TernarySearchTree.h ../../AlgAndDataStructures/TextTools.h ../../AlgAndDataStructures/SpellCorrector.cpp ../../AlgAndDataStructures/SpellCorrector.h ../messages/Message_I.h ../messages/MessageCorrect.cpp ../messages/MessageCorrect.h ../messages/MessageSame.cpp ../messages/MessageSame.h ../messages/MessageClient.cpp ../messages/MessageClient.h)
add_executable(TCP_Server ${SOURCE_FILES})
