cmake_minimum_required (VERSION 3.7)
project(temple)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options("-ftemplate-depth=16834")

file(GLOB_RECURSE sources 
    "test/*.cpp"
)

add_executable(empty ${sources})
target_include_directories(empty PRIVATE "include")
