cmake_minimum_required(VERSION 3.10.0)
project(trash_file)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Include Boost as an imported target
find_package(Boost 1.65 COMPONENTS program_options unit_test_framework log REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(TfUtils)
add_subdirectory(TfTools)
add_subdirectory(app)
add_subdirectory(test)
