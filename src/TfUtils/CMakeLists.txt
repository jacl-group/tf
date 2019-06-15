#
# TfUtils cmake
#
# Created by cenicol on 6/9/19.
#

message("")

# Define library. Only source files here!
project(TfUtils VERSION 0.1 LANGUAGES CXX)

message("TfUtils PROJECT_NAME: ${PROJECT_NAME}")

# Collect using glob the source files
file(GLOB SOURCES "src/*.cpp" "include/TfUtils/*.hpp")

add_library(TfUtils ${SOURCES})

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
message("TfUtils BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message("TfUtils INSTALL_INTERFACE: include")
target_include_directories(TfUtils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# Depend on a library that we defined in the top-level file
target_link_libraries(TfUtils
    TfTools
    Boost::program_options
    )

message("")

