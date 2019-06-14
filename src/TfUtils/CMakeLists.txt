#
# TfUtils cmake
#
# Created by cenicol on 6/9/19.
#

# Define library. Only source files here!
project(TfUtils VERSION 0.1 LANGUAGES CXX)

# Collect using glob the source files
file(GLOB SOURCES "src/*.cpp" "include/TfUtils/*.hpp")

add_library(TfUtils ${SOURCES})

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
message("")
message("TfUtils BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message("TfUtils INSTALL_INTERFACE: include")
message("")
target_include_directories(TfUtils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# If we have compiler requirements for this library, list them
# here
#target_compile_features(lib
#    PUBLIC cxx_auto_type
#    PRIVATE cxx_variadic_templates)

# Depend on a library that we defined in the top-level file
target_link_libraries(TfUtils
    TfTools
    Boost::program_options
    )

