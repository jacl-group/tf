#
# Application cmake
#
# Created by cenicol on 6/9/19.
#

# Collect using glob the source files
file(GLOB SOURCES "*.cpp")

# Define an executable
add_executable(tf ${SOURCES})

# Define the libraries this project depends upon
target_link_libraries(tf TfUtilsLib Boost::program_options)