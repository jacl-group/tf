cmake_minimum_required(VERSION 3.10.0)
project(trash_file)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include Boost as an imported target
find_package(Boost 1.65 COMPONENTS program_options unit_test_framework REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")

include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect using glob the source files
#file(GLOB SOURCES "src/*.cpp")

# Define an executable
#add_executable(tf ${SOURCES})

# Define the libraries this project depends upon
#target_link_libraries(tf TfUtilsLib Boost::program_options)

add_subdirectory(TfUtils)
add_subdirectory(TfTools)
add_subdirectory(app)
add_subdirectory(test)
