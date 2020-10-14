# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("Monopoly TXT")

# Include sub-projects.
include_directories(${CMAKE_SOURCE_DIR}/src)
add_subdirectory ("src")
