cmake_minimum_required(VERSION 3.10.0)
project(trash_file)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
#INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
#TARGET_LINK_LIBRARIES( anyExecutable LINK_PUBLIC ${Boost_LIBRARIES} )

# Include Boost as an imported target
find_package(Boost 1.65 COMPONENTS program_options REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")

file(GLOB SOURCES "src/*.cpp")

add_executable(tf ${SOURCES} src/TfOptions.cpp include/TfOptions.hpp src/Utils.cpp include/Utils.hpp src/BoostParser.cpp include/BoostParser.hpp)

target_link_libraries(tf Boost::program_options)
