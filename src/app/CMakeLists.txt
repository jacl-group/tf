#
# Application cmake
#
# Created by cenicol on 6/9/19.
#

# Collect using glob the source files
file(GLOB SOURCES "src/*.cpp")
message("\ntf SOURCES: ${SOURCES}\n")

# Define an executable
add_executable(tf ${SOURCES})

# Define the libraries this project depends upon
target_link_libraries(tf TfUtils TfTools
        Boost::program_options
        Boost::thread
        Boost::log
        )
