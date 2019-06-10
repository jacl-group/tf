#
# TfUtils cmake
#
# Created by cenicol on 6/9/19.
#

# Define library. Only source files here!
project(TfUtilsLib VERSION 0.1 LANGUAGES CXX)

# Collect using glob the source files
file(GLOB SOURCES "*.cpp")

add_library(TfUtilsLib ${SOURCES})

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
message("")
message("TfUtilsLib BUILD_INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message("TfUtilsLib INSTALL_INTERFACE: include")
message("")
target_include_directories(TfUtilsLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# If we have compiler requirements for this library, list them
# here
#target_compile_features(lib
#    PUBLIC cxx_auto_type
#    PRIVATE cxx_variadic_templates)

# Depend on a library that we defined in the top-level file
target_link_libraries(TfUtilsLib
    Boost::program_options
    )

