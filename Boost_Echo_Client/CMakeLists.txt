cmake_minimum_required(VERSION 3.8)
project(Boost_Echo_Client)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/connectionHandler.h
        src/connectionHandler.cpp
        src/BBclient.cpp include/BBclient.h src/Task.cpp include/Task.h src/echoClient.cpp)
link_libraries(boost_system boost_thread)
add_executable(Boost_Echo_Client ${SOURCE_FILES})
