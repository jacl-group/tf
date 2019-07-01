#
# Unit Tests cmake
#
# Created by cenicol on 6/9/19.
#

message("CMAKE_ROOT: ${CMAKE_ROOT}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# Collect using glob the source files
file(GLOB SOURCES "*.cpp")

# Parser Unit Test
add_executable(parserTest ${SOURCES})
target_link_libraries(parserTest
        TfUtils
        TfTools
        Boost::unit_test_framework
        Boost::log
        Boost::thread
        Threads::Threads
        )
