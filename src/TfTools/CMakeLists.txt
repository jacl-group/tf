#
# TfTools cmake
#
# Created by cenicol on 6/9/19.
#

message("")

# Define library. Only source files here!
project(TfTools VERSION 0.1 LANGUAGES CXX)
message("TfTools PROJECT_NAME: ${PROJECT_NAME}")

# Collect using glob the source files
file(GLOB SOURCES "src/*.cpp" "include/${PROJECT_NAME}/*.hpp")

add_library(TfTools ${SOURCES})

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
message("TfTools BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message("TfTools INSTALL_INTERFACE: include")
target_include_directories(TfTools PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# Depend on a library that we defined in the top-level file
target_link_libraries(TfTools
    Boost::program_options
    )

message("")
