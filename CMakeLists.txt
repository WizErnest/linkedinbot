cmake_minimum_required(VERSION 3.13)
project(LinkedInBot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -static-libstdc++ -static-libgcc")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

include_directories(./include)

set(SOURCE_FILES
        src/main.cpp
        src/Person.cpp
        src/MessageCreator.cpp)

add_executable(LinkedInBot ${SOURCE_FILES})